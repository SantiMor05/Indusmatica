#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t child=fork(),mypid;

    if(child){
        fprintf(stderr,"El fork devolvió %d, significa que estoy en el padre con pid = %d\n",child,getpid());
        sleep(1);
    }
    else{
        fprintf(stderr,"El fork devolvió %d, estoy en el hijo con pid = %d\n",child,getpid());
        fprintf(stderr,"Mi padre es %d\n",mypid=getppid());
        char comando[200]={};
        char ruta[30]="~/Edward/Labs/Lab2/Guia2";
        snprintf(comando,sizeof(comando),"pstree -s %d > %s/pstree.txt",mypid,ruta);
        system(comando);
    }
    return 0;
}
