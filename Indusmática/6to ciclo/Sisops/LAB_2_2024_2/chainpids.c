#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

int main(int narg, char *arg[]){
    if(narg!=2){
        printf("No hay 2 argumentos");
        exit(1);
    }
    pid_t hijo,padre=getpid();
    int n=atoi(arg[1]),i;
    printf("--------------------------\n");
    for(i=1;i<=n;i++)
        if((hijo=fork())!=0)break;
    printf("pid(%d)  pid%d(%d)\n",getpid(),i,hijo);
    if(i==n+1){
        printf("--------------------------\n");
    }
    waitpid(hijo,NULL,0);
    return 0;
}
