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
    wait(NULL);
    val2=fork();
    wait(NULL);
    val3=fork();
    wait(NULL);
    printf("Estoy en: %d,  val1=%d, val2=%d, val3=%d\n",getpid(),val1,val2,val3);
    exit(0);

}