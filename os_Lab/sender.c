#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/msg.h>
struct message{
    long mtype;
    char mtext[100];
}message;
int main (){
    key_t key;
    int msgid;
    key = ftok("progfile",65);
    msgid = msgget(key,0666 | IPC_CREAT);
    printf("Entire message to send :");
    fgets(message.mtext,sizeof(message.mtext),stdin);
    message.mtype = 1;
    msgsnd(msgid, &message, sizeof(message),0);
    printf("message Sent Successfully");
    return 0;
}