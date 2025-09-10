#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
    int i,status;
    pid_t child,pid_padre;

    pid_padre=getpid();
    for(i=1;i<4;i++)
        if((child=fork())<=0)break;
        else fprintf(stderr,"Este es el ciclo Nro %d\n y se esta creando el proceso %d\n",i,child);
    if(pid_padre==getpid()) {
        char cad[100];
        sprintf(cad,"pstree -p %d > fanp.txt",pid_padre);
        system(cad);
        for(i=1;i<4;i++)wait(&status);
    }
    fprintf(stderr,"Este es el proceso %d con padre %d\n",getpid(),getppid());
    return 0;
}