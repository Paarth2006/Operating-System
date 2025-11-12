#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    char buffer[50];
    int fd[2];
    char message[] = "Hello from Parent";
    pipe(fd);
    if (fork()==0){
        read(fd[0],buffer,sizeof(buffer));
        printf("Child got : %s\n",buffer);
    }
    else{
        write(fd[1],message,sizeof(message));
    }
    return 0;
}  