#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
int p[2];
pipe(p);

void *t11(void *gp)
{
}

void *t12(void *gp)
{

 close(p[0]);
 int a,b;
 printf("Enter 2 numbers:");
 scanf("%d",&a);
 scanf("%d",&b);
 write(p[1],&a,sizeof(a));
 write(p[1],&b,sizeof(b));

}

void *t21(void *gp)
{

}

void *t22(void *gp)
{
 close(p[1]);
 int a1,b2;
 read(p[0],&a1,sizeof(a1));
 read(p[0],&b2,sizeof(b2));
 printf("Entered number is :%d,%d\n",a1,b2);
 close(p[0]);
}


int main(){
int i;
pid_t pid1,pid2;
pthread_t tpid1,tpid2;
pid1=fork();
if(pid1){
printf("Process1 is created\n");
pthread_create(&tpid1,NULL,t12,NULL);
pthread_join(tpid1,NULL);
}
else{
printf("Process2 is created\n");
pthread_create(&tpid2,NULL,t22,NULL);
pthread_join(tpid2,NULL);
}

return 0;
}
