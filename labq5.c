#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<unistd.h>

sem_t mutex,writeblock;
int data = 0,rcount = 0;
/*
void *reader(void *arg)
{
  int f;
  f = ((int)arg);
  sem_wait(&mutex);
  rcount = rcount + 1;
  if(rcount==1)
   sem_wait(&writeblock);
  sem_post(&mutex);
  printf("Data read by the reader%d is %d\n",f,data);
  sleep(1);
  sem_wait(&mutex);
  rcount = rcount - 1;
  if(rcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
  sem_wait(&writeblock);
  data++;
  printf("Data writen by the writer%d is %d\n",f,data);
  sleep(1);
  sem_post(&writeblock);
}
*/

int main()
{ //sem_init(&mutex,0,1);
  //sem_init(&writeblock,0,1);
      key_t key = ftok("shmfile",65);
      int shmid = shmget(key,1024,0666|IPC_CREAT);
      int *num = (int *) shmat(shmid,NULL,0);
      (*num)=0;
      shmdt(num);
  
  pid_t pid1;
  pid1=fork();
  if(pid1){
    for(int i=0;i<5;i++){
      key_t key = ftok("shmfile",65);
      int shmid = shmget(key,1024,0666|IPC_CREAT);
      int *num = (int *) shmat(shmid,NULL,0);
      printf("Data read from memory by P1: %d\n",*num);
      printf("Incremented value by P1: %d\n",++(*num));
      shmdt(num);
    }
    
  }
  else{
      for(int i=0;i<5;i++){
        key_t key = ftok("shmfile",65);
        int shmid = shmget(key,1024,0666|IPC_CREAT);
        int *num = (int*) shmat(shmid,NULL,0);
        printf("Data read from memory by P2: %d\n",*num);
        printf("Incremented value by P2: %d\n",++(*num));
        shmdt(num);
        shmctl(shmid,IPC_RMID,NULL);
      }

  }
  return 0;
}
