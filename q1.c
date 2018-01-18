#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
int p[2];

void *t11(void *gp)
{ char str[20];
  int i,result;
 printf("Executing thead T11\n");
 printf("Enter 5 strings\n");
 close(p[0]);
 for(i=0;i<5;i++){
   scanf("%s",&str);
   result=write(p[1],str,strlen(str)+1);
   if(result<0)
	printf("Pipewrite error");
 }
 close(p[1]);
}

void *t12(void *gp)
{

 printf("Executing thread T12\n");
 int a,result,i;
 printf("Enter 5 numbers:\n");
 close(p[0]);
 for(i=0;i<5;i++){
 scanf("%d",&a);
 result=write(p[1],&a,sizeof(int));
 if (result < 0)
   printf("pipewrite error\n");
 }
close(p[1]);

}

void *t21(void *gp)
{
   printf("Executing Thread T21\n");
 int a1,i;
 char str[20],l[20]="a";
 for(i=0;i<5;i++){
  read(p[0],str,20);
  if(strlen(l)<strlen(str))
   strcpy(l,str);
 }
 close(p[0]);
printf("Largest String is:%s\n",l);

}

void *t22(void *gp)
{

 printf("Executing Thread T22\n");
 int a1,i,l=0;
 for(i=0;i<5;i++){
  read(p[0],&a1,sizeof(int));
  if(a1>l)
   l=a1;
 }
 close(p[0]);
printf("Largest Number is:%d\n",l);
}


int main(){

int i,result;
result=pipe(p);
pid_t pid1;
pthread_t tpid12,tpid21,tpid11,tpid22;
pid1=fork();
if(pid1){

pthread_create(&tpid11,NULL,t11,NULL);
pthread_join(tpid11,NULL);

}
else{
pthread_create(&tpid21,NULL,t21,NULL);
pthread_join(tpid21,NULL);
}

return 0;
}
