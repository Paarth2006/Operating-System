#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    int fd[2];
    char* message = "Hello, FIFO!";
    char * FIFO_FILE = "fifo.txt";
    mkfifo(FIFO_FILE, 0666);

    fd[1] = open(FIFO_FILE, O_WRONLY);
    write(fd[1], message, strlen(message) + 1);
    printf("Wrote to FIFO: %s\n", message);
    close(fd[1]);

    return 0;
}