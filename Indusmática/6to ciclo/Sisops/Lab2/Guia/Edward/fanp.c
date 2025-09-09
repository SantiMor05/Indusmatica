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
        if(!child)break;
    }
    if(!child)sleep(1);
    else{
        char comando[100]={};
        snprintf(comando,sizeof(comando),"pstree -p %d > fanp.txt",mayor);
        system(comando);
        for (int i = 0; i < 3; i++)
        {
            waitpid(-1,NULL,0);
        }
        
    }
    return 0;
}