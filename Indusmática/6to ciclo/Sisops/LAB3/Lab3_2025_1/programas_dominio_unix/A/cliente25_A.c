#include <sys/un.h>
#include <sys/socket.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h> 

#define SV_SOCK_PATH "/tmp/us_xfr"

#define BUF_SIZE 100
#define BACKLOG 5

int
main(int argc, char *argv[])
{
    struct sockaddr_un addr;
    int sfd;
    ssize_t numRead;
    char buf[BUF_SIZE];

    sfd = socket(AF_UNIX, SOCK_STREAM, 0);      /* Create client socket */
    if (sfd == -1)
        perror("socket");
    
    /* Construct server address, and make the connection */

    memset(&addr, 0, sizeof(struct sockaddr_un));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, SV_SOCK_PATH, sizeof(addr.sun_path) - 1);

    if (connect(sfd, (struct sockaddr *) &addr,
                sizeof(struct sockaddr_un)) == -1)
        perror("connect");
    
    srand(getpid());
    int cantNum = rand() % 10 +1;
    write(sfd,&cantNum,sizeof(int));
    int numeros[cantNum];
    int factoriales[cantNum];
    
    
    for(int i=0; i< cantNum;i++){
        numeros[i] = rand() % 10;
        write(sfd,&numeros[i],sizeof(int));
    }
    
    for(int i=0; i< cantNum;i++){
        read(sfd,&factoriales[i],sizeof(int));
    }
    
    printf("Cliente con pid %d: ",getpid());
    for(int i=0;i<cantNum;i++){
        printf("%d(%d) ", factoriales[i],numeros[i]);    
    }
    printf("\n");
    
    
    close(sfd);    

    exit(EXIT_SUCCESS);         /* Closes our socket; server sees EOF */
}
