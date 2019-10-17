#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 1
#define BUFSIZEX 512

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    char buf2[BUFSIZEX];
    int n;
    if(argc == 2) {
        n = 5;
    } else {
        n = atoi(argv[1]);
    }
    int counter = 0;
    int fd;
    if((fd = open(argv[2], O_RDONLY)) < 0){
        printf("error");
        return 0;
    }
    lseek(fd, 0, SEEK_END);
    int m;
    int n1 = -2;
    int z;
    lseek(fd, -2, SEEK_END);

    while((m = read(fd, buf, BUFSIZE)) > 0) {
        n1 = n1 - 1;
        lseek(fd, n1, SEEK_END);
        if(buf[0] == '\n') {
            counter = counter + 1;
        }
        if(counter == n) {
            lseek(fd, 2, SEEK_CUR);
            while((z = read(fd, buf2, BUFSIZEX)) > 0) {
                write(STDOUT_FILENO, buf2, z);
            }
            return 0;
        }
    }
    return 0;
    
}
