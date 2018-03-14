#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/mman.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<semaphore.h>

sem_t mutex;
#define SHSIZE 10 
#define NAME "assign4"



int main()
{

  int status;
  int pid;
  int i,n,m;
  int shm_fd;
  void* ptr;
  
  /* create the shared memory object */
  shm_fd = shm_open(NAME, O_CREAT | O_RDWR, 0666);

  /* configure the size of the shared memory object */
  ftruncate(shm_fd, SHSIZE);

  /* memory map the shared memory object */
  ptr = mmap(NULL, SHSIZE, PROT_WRITE, MAP_SHARED, shm_fd, 0);

  *(int *)ptr =0;
  
  
  sem_init(&mutex,0,1); //semaphore initialisation
  
  
  printf("\n Child Increment shared memory by : ");
  scanf("%d",&m);

  printf("\n Parent Increment shared memory by : ");
  scanf("%d",&n);

  
   
   if ((pid = fork()) < 0) {
     perror("Child Process Creation Error:");
     exit(1);
   }
   
   if (pid == 0) 
   {
	//child process    
	     
	     
	     sem_wait(&mutex);
	      
	        *(int *)ptr = *(int *)ptr + m;	      
	      printf("\n Value of shared memory after child increments it : %d\n",*(int *)ptr);
	     sem_post(&mutex);
   }
   
   
   if (pid != 0) 
   {
	    //parent process      
	     
	     sem_wait(&mutex);
	     	      
	         *(int *)ptr = *(int *)ptr + n;
	      printf("\n Value of shared memory after parent increments it  : %d\n",*(int *)ptr);
	     sem_post(&mutex);
	     
	     
	     // wait for child to complete
	     wait(&status);
	     
	     
   }

  
  /* remove the shared memory object */
    shm_unlink(NAME);
    
  return 0;
}

