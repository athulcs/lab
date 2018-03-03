#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<string.h>
#define SIZE 10
int *integer=0;
void main()
{
int shmid;
key_t key_10;
char *shm;
int semid,pid;
shmid=shmget((key_t)10,SIZE,IPC_CREAT|0666);
shm=shmat(shmid,NULL,0);
semid=semget(0x20,1,IPC_CREAT|0666);
integer=(int *)shm;
pid=fork();
if(pid==0)
{
	int i=0;
	while(i<10)
	{
		sleep(2);
		printf("\n child process use shared memory");
		accessmem(semid);
		i++;
	}
}
else
{
	int j=0;
	while(j<10)
	{
		sleep(j);
		printf("\n parent versus shared memory");
		accessmem(semid);
		j++;
	}
}
shmctl(semid,IPC_RMID,0);
}

int accessmem(int semid)
{
struct sembuf sop; 
sop.sem_num=0;
sop.sem_op=-1;
sop.sem_flg=0;
semop(semid,&sop,1);
(*integer)++;
printf("\t integervariable=%d",(*integer));
sop.sem_num=0;
sop.sem_op=1;
sop.sem_flg=0;
semop(semid,&sop,1);
}