/*Process P1 and P2 increments the value of num 5 times.Num initially=0*/
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>

sem_t mutex;
int data = 0,rcount = 0;

int main()
    { sem_init(&mutex,0,1);
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
      sem_wait(&mutex);
      printf("Data read from memory by P1: %d\n",*num);
      printf("Incremented value by P1: %d\n",++(*num));
      sem_post(&mutex);
      sleep(1);
      shmdt(num);
    }
    
  }
  else{
      for(int i=0;i<5;i++){
        key_t key = ftok("shmfile",65);
        int shmid = shmget(key,1024,0666|IPC_CREAT);
        int *num = (int*) shmat(shmid,NULL,0);
        sem_wait(&mutex);
        printf("Data read from memory by P2: %d\n",*num);
        printf("Incremented value by P2: %d\n",++(*num));
        sem_post(&mutex);
        shmdt(num);
      }

  }
  return 0;
}