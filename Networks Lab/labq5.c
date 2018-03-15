#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>

sem_t mutex,writeblock;
int readcount = 0,*data;

void *reader(void *arg)
{
  int f;
  f = (intptr_t)arg;
  sem_wait(&mutex);
  readcount++;
  if(readcount==1)
   sem_wait(&writeblock);
  sem_post(&mutex);
  printf("Data read by the reader%d is %d\n",f,*data);
  sem_wait(&mutex);
  sleep(1);
  readcount--;
  if(readcount==0)
   sem_post(&writeblock);
  sem_post(&mutex);
}

void *writer(void *arg)
{
  int f;
  f = (intptr_t) arg;
  sem_wait(&writeblock);
  ++(*data);
  printf("Data writen by the writer%d is %d\n",f,*data);
  sleep(1);
  sem_post(&writeblock);
}

int main()
{
  int i;  
  int shm_fd = shm_open("shmfile", O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, 10);
  data = mmap(NULL, 10, PROT_WRITE, MAP_SHARED, shm_fd, 0);
  (*data)=0;
  pthread_t rdthread[3],wrthread[3];
  sem_init(&mutex,0,1);
  sem_init(&writeblock,0,1);
  for(i=0;i<3;i++)
  {
    pthread_create(&wrthread[i],NULL,writer,(void *)(intptr_t)i);
    pthread_create(&rdthread[i],NULL,reader,(void *)(intptr_t)i);
  }
  for(i=0;i<3;i++)
  {
    pthread_join(wrthread[i],NULL);
    pthread_join(rdthread[i],NULL);
  }
  return 0;
}