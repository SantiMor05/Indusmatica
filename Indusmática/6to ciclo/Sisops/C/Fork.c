#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


int main(){
    
    printf("Hola mundo ");
    fflush(stdout);
    pid_t pid = fork();
    int a=30;
    
    if(pid == 0){
        printf("Soy el hijo, mi PID es %d\n",getpid());
    } else{
        printf("Soy el padre, mi hijo tiene PID %d\n", pid);
    }
    
    printf("El valor de a es: %d\n",a);

    return 0;
}