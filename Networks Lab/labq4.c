/*Process P1 and P2 increments the value of num 5 times.Num initially=0*/
#include<stdio.h>
#include<semaphore.h>
#include<sys/shm.h>
#include<unistd.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>

sem_t mutex;
int data = 0,rcount = 0;

int main()
{ sem_init(&mutex,0,1);
  int shm_fd = shm_open("shmfile", O_CREAT | O_RDWR, 0666);
  ftruncate(shm_fd, 10);
  int *num = mmap(NULL, 10, PROT_WRITE, MAP_SHARED, shm_fd, 0);
  (*num)=0;
  shmdt(num);  
  pid_t pid1;
  pid1=fork();
  if(pid1){
    for(int i=0;i<5;i++){
      sem_wait(&mutex);
      printf("Data read from memory by P1: %d\n",*num);
      printf("Incremented value by P1: %d\n",++(*num));
      sem_post(&mutex);
      sleep(1);
    }
    
  }
  else{
      for(int i=0;i<5;i++){
        int shm_fd = shm_open("shmfile", O_CREAT | O_RDWR, 0666);
        ftruncate(shm_fd, 10);
        int *num = mmap(NULL, 10, PROT_WRITE, MAP_SHARED, shm_fd, 0);
        sem_wait(&mutex);
        printf("Data read from memory by P2: %d\n",*num);
        printf("Incremented value by P2: %d\n",++(*num));
        sem_post(&mutex);
      }

  }
  shm_unlink("shmfile");
  return 0;
}
