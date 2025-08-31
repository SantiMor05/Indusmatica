#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

// ls | wc

void pipeline(const char *process1,const char *process2){
    int fd[2];
    pipe(fd);

    if(fork()!=0){
        //padre o Procesa A
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execlp(process1,process1,NULL);
    }
    else{
        //hijo O proceso B
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        execlp(process2,process2,NULL);
    }

}

//para argumentos y textos
void pipeline2( char *arg1[],char *arg2[]){
    int fd[2];
    pipe(fd);

    if(fork()!=0){
        //padre
        wait(NULL);
        close(fd[0]);
        close(1);
        dup(fd[1]);
        close(fd[1]);
        execvp(arg1[0],arg1);
    }
    else{
        //hijo
        close(fd[1]);
        close(0);
        dup(fd[0]);
        close(fd[0]);
        execvp(arg2[0],arg2);
    }

}

int main(){
    //execlp("echo","echo","hola","Mundo","que tal",NULL);
    char *ls_arg1[] = {"echo","hola","mundo",NULL};
    char *ls_arg2[] = {"wc",NULL};
    //pipeline("ls","wc");
    pipeline2(ls_arg1,ls_arg2);

    return 0;

}