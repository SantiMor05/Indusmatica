#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){

    pid_t val1=-1,val2=-1,val3=-1,old;

    printf("Pid padre: %d\n",old=getpid());
    fflush(stdout);
    val1=fork();
    val2=fork();
    val3=fork();
    if(old==getpid()){
        char command[100];
        snprintf(command,sizeof(command),"pstree -p %d > multiforkV2.txt",old);
        system(command);
        //while(waitpid(-1,NULL,0)>-1);
    }
    else sleep(1);
    exit(0);

}