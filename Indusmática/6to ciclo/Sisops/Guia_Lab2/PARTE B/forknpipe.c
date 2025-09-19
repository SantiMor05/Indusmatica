#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

int main(){
    char buff[64];
    char messege[]="Hola, que pasa\n";
    int ii,fd[2];
    pipe(fd);
    if(fork()==0){ // hijo
        close(fd[0]);
        printf("Soy el PID[%d] (hijo)\n",getpid());
        for(ii=0;ii<5;ii++)
        write(fd[1],messege,sizeof(messege)-1);
        close(fd[1]);
    }
    else{ //padre
        close(fd[1]);
        printf("Soy el PID[%d] (padre)\n",getpid());
        memset(buff,0,sizeof(buff));
        while((ii=read(fd[0],buff,sizeof(buff)-1)!=0)){
            printf("Padre lee[%d]:\n%s\n",ii,buff);
            memset(buff,0,sizeof(buff));
        }
        close(fd[0]);
    }
    return 0;
}