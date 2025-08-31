#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define STD_IN 0

int main(int argc, char *argv[]){
    pid_t pid;
    int np,status;
    np = argc - 1;

    for(int i=1;i<=np;i++){
        if((pid=fork())==-1){perror("fallor el fork\n");
            exit(1);        
        }
        else if(pid==0){
            //hijo
            execl("./Input","Input",argv[i],NULL);
            perror("fallor el exec\n");
            exit(2);
        }  
        else{
           wait(NULL); 
        }
    }

    return 0;
}
