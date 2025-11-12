#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct message{
    long mtype;
    char mtext[100];
}message;
int main(){
    key_t key;
    int msgid;
    key = ftok("progfile",65);
    msgid = msgget(key,0666 | IPC_CREAT);
    msgrcv(msgid , &message , sizeof(message),1,0);
    printf("Message Recieved %s\n",message.mtext);
    msgctl(msgid,IPC_RMID,NULL);
    return 0 ;
}