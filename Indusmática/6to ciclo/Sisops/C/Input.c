#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

#define STD_IN 0

int main(int argc, char *argv[]){
    int c, fd;

    if (argc == 2) {
        close(STD_IN);
        fd = open(argv[1],O_RDONLY);
        //dup(fd);
        //close(fd);
    }

    while((c= getchar()) != EOF) putchar(toupper(c));

    return 0;
}



