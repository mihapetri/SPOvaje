#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {

    char *buf[BUFSIZE];
    if(argc != 3) {
        printf("Potrebujem 2 argumenta!\n");
        return 1;
    }

    int fd1;
    int fd2;

    if((fd1 = open(argv[1], O_RDONLY)) == -1) {
        printf("Datoteka 1 ni odprta za branje!\n");
        return 1;
    }

    if(open(argv[2], O_WRONLY) == -1) {
        printf("Datoteka 2 ni odprta za pisanje!\n");
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    int n;
    
    while((n = read(fd1, buf, BUFSIZE)) > 0) {
        if(write(fd2, buf, n) != n) {
            printf("write error\n");
            return 1;
        }
    }
    if( n < 0) {
        printf("write error2\n");
            return 1;
    }

    return 0;
}
