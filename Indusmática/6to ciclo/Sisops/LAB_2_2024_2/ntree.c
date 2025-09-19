#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

void crearArboles(int n,int niveles,pid_t padre){
    pid_t hijo;
    if(niveles<=0)return;
    for(int i=0;i<n;i++)
        if((hijo=fork())<=0)
            break;
        else {
            printf("Soy el proceso %d con pid %d y ppid %d\n",niveles,getpid(),getppid());
        }
    if(hijo==0) {
        crearArboles(n,niveles-1,padre);
        sleep(2);
        exit(2);
    }
    if(getpid()==padre){
        sleep(1);
        char cad[100];
        sprintf(cad,"%d",padre);
        execlp("pstree","pstree","-p",cad,NULL);
    }
    //for(int i=0;i<n;i++)wait(NULL);
}

int main(int narg,char *argv[]){
    if(narg!=2){
        printf("No hay 2 argumentos\n");
        exit(1);
    }
    int n=atoi(argv[1]);
    pid_t padre=getpid();
    if(n<=1){
        printf("El numero no es mayor a 1\n");
        exit(1);
    }
    crearArboles(n,n,padre);
    while(wait(NULL)>0);
    return 0;
}