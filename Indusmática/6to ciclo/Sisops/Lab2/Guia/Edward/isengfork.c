#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t root;
    int i=0;
    if(fork()==0){
        i++;
        printf("pid: %d  i=%d\n",getpid(),i);
        fflush(stdout);
    }
    wait(NULL);
    if(fork()==0){
        i++;
        printf("pid: %d  i=%d\n",getpid(),i);
        fflush(stdout);
    }
    wait(NULL);
    if(fork()==0){
        i++;
        printf("pid: %d  i=%d\n",getpid(),i);
        fflush(stdout);
    }
    wait(NULL);    
    //printf("Result: %3d\n",i);
    exit(0);
}