#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
int main() {
    int fd[2];
    char buffer[100];
    char * FIFO_FILE = "fifo.txt";
    fd[0] = open(FIFO_FILE, O_RDONLY);
    read(fd[0], buffer, 100);
    printf("Read from FIFO: %s\n", buffer);
    close(fd[0]);
    return 0;
}
