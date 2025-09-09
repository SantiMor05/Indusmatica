#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t child,myself,parent;
    int mayor=getpid();
    for (int i = 0; i < 3; i++)
    {
        child=fork();
        if(child)break;
    }
    if(wait(NULL)==-1){
        char comando[100]={};
        snprintf(comando,sizeof(comando),"pstree -p %d > chainp.txt",mayor);
        system(comando);
    }
    return 0;
}