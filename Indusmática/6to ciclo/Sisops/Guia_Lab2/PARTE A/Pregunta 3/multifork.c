#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#define DISPLAY1 "PID INDuK** ** pid (%5.5d) ** ***********\n"
#define DISPLAY2 "val1(%5.5d) -- val2(%5.5d) -- val3(%5.5d)\n"

int main(){
    pid_t val1,val2,val3;
    pid_t padre=getpid();
    printf(DISPLAY1,(int)getpid());
    fflush(stdout);

    /*if (fork() == 0) {
        sleep(2); // esperar a que los otros fork + waits sucedan
        char cmd[100];
        sprintf(cmd, "pstree -p %d > multifork.txt", padre);
        system(cmd);
        exit(0);
    }*/

    val1 = fork();
    //waitpid(-1,NULL,0);
    val2 = fork();
    //waitpid(-1,NULL,0);
    val3 = fork();
    //waitpid(-1,NULL,0);

    if(padre==getpid()){
        char cmd[100];
        sprintf(cmd, "pstree -p %d > multifork.txt", padre);
        system(cmd);
    } 

    printf(DISPLAY2 ,(int)val1,(int)val2,(int)val3);
    if(getpid()!=padre)sleep(2);
   // while (wait(NULL) > 0);
    return 0;
}

//13638 - papa
/*val1(00000) -- val2(00000) -- val3(00000) 
val1(00000) -- val2(00000) -- val3(13644) 
val1(00000) -- val2(13643) -- val3(00000) 
val1(00000) -- val2(13643) -- val3(13645) 
val1(13642) -- val2(00000) -- val3(00000) 
val1(13642) -- val2(00000) -- val3(13647) 
val1(13642) -- val2(13646) -- val3(00000) 
val1(13642) -- val2(13646) -- val3(13648)*/