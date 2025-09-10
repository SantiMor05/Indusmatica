#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

void crearArbol(int n,int num,pid_t padre){
    printf("Soy el proceso %d con pid %d y ppid %d\n",num,getpid(),getppid());
    if(n<=1)return;
    if(fork()==0){
        crearArbol(n-1,2*num,padre);
        sleep(2);
        exit(1);
    }
    if(fork()==0){
        crearArbol(n-1,2*num+1,padre);
        sleep(2);
        exit(1);
    }
    if(getpid() == padre){
        sleep(1); // esperar a que los hijos estén vivos
        char cmd[100];
        sprintf(cmd, "pstree -p %d > binarytree.txt", padre);
        system(cmd);
        printf("Árbol de procesos guardado en binarytree.txt\n");
        wait(NULL);
        wait(NULL);
    }

    //wait(NULL);
    //wait(NULL);
}


int main(int narg,char *argv[]){

    pid_t padre=getpid();
    if(narg!=2) {
        fprintf(stderr,"Falta la profundidad");
        exit(0);
    }
    int n= atoi(argv[1]);
    crearArbol(n,1,padre);

    
   

    return 0;
}