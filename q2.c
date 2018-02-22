/*Create 2 processes and communicate between these 2 processes using shared memory*/

#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
int main()
{
    key_t key = ftok("shmfile",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *str = (char*) shmat(shmid,(void*)0,0);
    printf("Write Data : ");
    gets(str);
    printf("Data written in memory: %s\n",str);
    shmdt(str);
    pid_t pid1;
    pid1 = fork();
    if(pid1==0){
      key_t key = ftok("shmfile",65);
      int shmid = shmget(key,1024,0666|IPC_CREAT);
      char *str = (char*) shmat(shmid,(void*)0,0);
      printf("Data read from memory: %s\n",str);
      shmdt(str);
      shmctl(shmid,IPC_RMID,NULL);
    }
    return 0;
}
