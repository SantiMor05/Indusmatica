#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <time.h>



int main(void) {
	int i,child,status;
	int fdPares[2],fdImpares[2];
	pipe(fdPares);
	pipe(fdImpares);
	child = fork();
	if (child < 0) {
			perror("fork");
			exit(1);
	}

	if (child == 0) {
		// Proceso hijo 1
		sleep(1);
		close(fdPares[0]);
		srand(time(NULL));
		int x, mypid=getpid(),num,fd;
		for(x=0;x<10;x++) {
			num=rand()%501;
			if(num%2==0)fd=fdPares[1];
			else fd=fdImpares[1];
			write(fd,&num,sizeof(num));
			write(fd,&mypid,sizeof(mypid));
		}
		close(fdPares[1]);
		close(fdImpares[1]);
	//     sleep(1);
		int valor,suPid;
		while(1){
			if(read(fdImpares[0],&valor,sizeof(int))==0)break;
			read(fdImpares[0],&suPid,sizeof(int));
			printf("Hijo 1 pid %d, numero impar %d, escrito por pid=%d\n",mypid,valor,suPid);
		}
		close(fdImpares[0]);
		printf("termine 1\n");
		exit(0);  
	}

	child = fork();
	if (child < 0) {
			perror("fork");
			exit(1);
	}
	if (child == 0) {
			// Proceso hijo 2
		sleep(1);
		close(fdImpares[0]);
		srand(time(NULL)+10);
		int x, mypid=getpid(),num,fd;
		for(x=0;x<10;x++) {
			num=rand()%501;
			if(num%2==0)fd=fdPares[1];
			else fd=fdImpares[1];
			write(fd,&num,sizeof(num));
			write(fd,&mypid,sizeof(mypid));
		}
		close(fdPares[1]);
		close(fdImpares[1]);
		//     sleep(1);
		int valor,suPid;
		while(1){
			if(read(fdPares[0],&valor,sizeof(int))==0)break;
			read(fdPares[0],&suPid,sizeof(int));
			printf("Hijo 2 pid %d, numero par %d, escrito por pid=%d\n",mypid,valor,suPid);
		}
		close(fdPares[0]);
		printf("termine 2\n");
		exit(0);
	}
	close(fdPares[0]);
	close(fdImpares[0]);
	close(fdPares[1]);
	close(fdImpares[1]);
	// Solo el padre hace wait si no ha sido eliminado
	for (i = 0; i < 2; ++i) {
			wait(&status);
	}
	return 0;
}


