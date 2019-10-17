#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFSIZE 512

int main(int argc, char *argv[]) {
    char buf[BUFSIZE];
    if(argc == 1) {
        int n;
        while((n = read(STDIN_FILENO, buf, BUFSIZE)) > 0) {
            write(STDOUT_FILENO, buf, n);
        }
        return 0;
    }
    int i;
    int fd;
    int m;
    for(i = 1; i < argc; i = i + 1) {
            fd = open(argv[i], O_RDONLY);
            while((m = read(fd, buf, BUFSIZE)) > 0) {
                if(write(STDOUT_FILENO, buf, m) != m) {
                    printf("error!");
                    return 0;
                }
            }
    }

    return 0;
    
}
