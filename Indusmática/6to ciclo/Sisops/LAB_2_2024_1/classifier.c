#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int fd[3][2];

void cerrarDescriptoresLectura(int i){
    if(i==0){
        close(fd[1][0]);
        close(fd[2][0]);
    }else if(i==1){
        close(fd[0][0]);
        close(fd[2][0]);
    }else{
        close(fd[0][0]);
        close(fd[1][0]);
    }
}

void impresion(int i){
    int r,ii;
   while((ii=read(fd[i][0],&r,sizeof(r))!=0)){
        printf("Proceseo %d tiene numero:  %d\n",i+1,r);
   }
}


int main(int na, char *argv[]){
	int n,i,pid,ii;
	
	if(na != 2) {
		fprintf(stderr, "Uso: %s <n>\n",argv[0]);
		exit(1);
	}
	n = atoi(argv[1]);
    for(int i=0;i<3;i++){close(fd[i][0]);close(fd[i][1]);} // padre le cierro los descriptores de los pipes
    for(int i=0;i<3;i++)pipe(fd[i]);
	for(i=0;i<3;i++) {
		if(!(pid = fork())) {
			int j,r, mypid;
			mypid = getpid();
			srand(mypid);	
            cerrarDescriptoresLectura(i);
			for(j=0;j<n;j++) {
			    r = rand() % 528 ;
                if(r%2 == 0){
                    write(fd[0][1],&r,sizeof(r)); // mando al proceso A, porque es para pares (descriptor de escritura)
                }
                else {
                    write(fd[1][1],&r,sizeof(r));// mando al proceso B, porque es para impares (descriptor de escritura)
                }
                if(r%10 == 1 || r%10==2 )
                    write(fd[2][1],&r,sizeof(r));// mando al proceso C, porque es para otros(descriptor de escritura)
			    //printf("%d %d\n",mypid,r);
			}   
            close(fd[0][1]);
            close(fd[1][1]);
            close(fd[2][1]);
            
            //impresion de los numeros para cada proceso respectivamente(pares,impares,otros)
            impresion(i);
			exit(0);    
		}	
	}
    sleep(1);
	exit(0);	
}

