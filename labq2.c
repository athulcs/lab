#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>

struct mesg_buffer {
    long mesgtype;
    char text[50];
} message;
 
int main()
{   pid_t pid1;
    pid1=fork();
    if(pid1){
        key_t key;
        int msgid;
        key = ftok("msgqfile", 65);
        msgid = msgget(key, 0666 | IPC_CREAT);
        message.mesgtype = 1;
        printf("Write Data : ");
        gets(message.text);
        msgsnd(msgid, &message, sizeof(message), 0);
        printf("Data send is : %s \n", message.text);
    }
    else{
        key_t key;
        int msgid;
        key = ftok("msgqfile", 65);
        msgid = msgget(key, 0666 | IPC_CREAT);
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Data Received is : %s \n",message.text);
        msgctl(msgid, IPC_RMID, NULL);
    }
 
    return 0;
}