#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){
    char buffer[50];
    int fd1[2], fd2[2];
    char messageChild[] = "Hello from Child";
    char messageParent[] = "Hello from Parent";
    pipe(fd1);
    pipe(fd2);
    if (fork()==0){
        write(fd2[1],messageChild,sizeof(messageChild));
        read(fd1[0],buffer,sizeof(buffer));
        printf("Child got %s\n",buffer);
    }else{
        write(fd1[1],messageParent,sizeof(messageParent));
        read(fd2[0],buffer,sizeof(buffer));
        printf("Parent got %s\n",buffer);
    }
    return 0;
}