#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    int fd1;
    int fd2;
    if((fd1 = open(argv[1], O_RDONLY | O_APPEND)) < 0) {
        printf("error1!");
    }
    if((fd2 = open(argv[2], O_WRONLY | O_TRUNC)) < 0) {
        printf("error2!");
    }

    int m;
    int n = -2;
    lseek(fd1, -2, SEEK_END);

    while((m = read(fd1, buf, BUFSIZE)) > 0) {
        n = n - 1;
        lseek(fd1, n, SEEK_END);
        if(write(fd2, buf, m) != m) {
            printf("error!");
            return 0;
        }
        if(lseek(fd1, 0, SEEK_CUR) == 0) {
            m = read(fd1, buf, BUFSIZE);
            write(fd2, buf, m);
            return 0;
        }
    }
    return 0;
    
}
