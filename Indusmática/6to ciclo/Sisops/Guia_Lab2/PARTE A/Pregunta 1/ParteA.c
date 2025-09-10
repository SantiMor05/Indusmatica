#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void){

    pid_t child;
    if((child=fork())){
        fprintf(stderr,"\nFOrk devolvio %d por tanto soy el padre con id = %d", child,getpid());
        wait(NULL);
    }
    else{
        fprintf(stderr,"\nFOrk devolvio %d por tanto soy el hijo con id = %d", child,getpid());
        char comando[100];
        // -s muestra los ancestros, -p agrega los PIDs
        sprintf(comando, "pstree -s %d > aprocesos.txt", getpid());

     
        system(comando);
    }

    return 0;
}