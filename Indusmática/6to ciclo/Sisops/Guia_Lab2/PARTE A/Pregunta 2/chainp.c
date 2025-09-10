#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void){
    int i,status;
    pid_t child,padre;
    padre = getpid();

    for (i = 1; i < 10; i++)
        if((child=fork()))break;
    fprintf(stderr,"Esta es la vuelta Nro %d\n",i);
    fprintf(stderr,"Recibi de fork el valor de %d\n", child);
    fprintf(stderr,"Soy el proceso %d con padre %d\n\n",getpid(),getppid() );
    
    if(child==0){
        char comando[100];
        sprintf(comando, "pstree %d > chainp.txt",padre);

        system(comando);
    }

    wait(&status);

    return 0;
}