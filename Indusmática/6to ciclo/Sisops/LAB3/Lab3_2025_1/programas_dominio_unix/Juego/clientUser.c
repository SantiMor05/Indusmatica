#include <sys/un.h>
#include <sys/socket.h>
#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
                           plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>  

#define SV_SOCK_PATH "/tmp/us_xfr"

#define BUF_SIZE 100

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

    /* Copy stdin to socket */

    int num;
    printf("Ingrese un numero: \n");
    scanf("%d",&num);
   
    write(sfd,&num,sizeof(int));
    
    int res;
    read(sfd,&res,sizeof(int));
    printf("\nTu respeusta es: %d\n",res);
    exit(EXIT_SUCCESS);         /* Closes our socket; server sees EOF */
}
