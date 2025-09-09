#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int arc,char**argv){

    printf("Hola");
    int fd[2];
    int n=atoi(argv[1]);
    if(n<=0){
        perror("Inserte un numero adecuado\n");
        exit(1);
    }
    if(pipe(fd)==-1){
        perror("Error en pipe inicial\n");
        exit(1);
    }
    dup2(fd[0],0);
    dup2(fd[1],1);
    if(close(fd[0])==-1 || close(fd[1])==-1){
        perror("Error al cerrar el pipe iniciall\n");
        exit(1);
    }
    pid_t child,dupResult;
    for (int i = 1; i < n; i++)
    {
        pipe(fd);
        child=fork();
        if(child) dupResult=dup2(fd[1],1);
        else dupResult=dup2(fd[0],0);
        if(dupResult==-1){
            fprintf(stderr,"Error al en dup de iteracion %d\n",i);
            exit(1);
        }
        if(close(fd[0])==-1 || close(fd[1])==-1){
            fprintf(stderr,"Error al cerrar el pipe de iteracion %d\n",i);
            exit(1);
        }
        if(child)break;
    }
    wait(NULL);
    fprintf(stderr,"Soy proceso %d, mi padre es %d\n",getpid(),getppid());
    return 0;
}