#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    int ii=0;
    pid_t padre=getpid();
    if(fork()==0)ii++;
    //waitpid(-1,NULL,0);
    if(fork()==0)ii++;
    //waitpid(-1,NULL,0);
    if(fork()==0)ii++;
    //waitpid(-1,NULL,0);
    printf("Result = %3.3d \n",ii);

    if(padre==getpid()){
        char cmd[100];
        sprintf(cmd, "pstree -p %d > isengfork.txt", padre);
        system(cmd);
    } 
    else sleep(2);

    return 0;
}