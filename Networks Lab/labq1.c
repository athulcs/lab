#include<stdio.h>
#include<unistd.h>
#include<string.h>
int p[2];
int q[2];
int main(){

int i,result;
pipe(p);
pipe(q);
pid_t pid1;
pid1=fork();
if(pid1){
 printf("Enter the message to be sent to P2 from P1:");
 char str[20];
 scanf("%s",&str);
 close(p[0]);
 result=write(p[1],str,strlen(str)+1);
 if(result<0)
   printf("Pipewrite error");
 close(p[1]);
 read(q[0],str,20);
 printf("Message Received by P1:%s\n",str);
 close(q[0]);
}

else{
 char str[20];
 read(p[0],str,20);
 printf("Message Received by P2:%s\n",str);
 close(p[0]);
 printf("Enter the message to be sent to P1 from P2:");
 scanf("%s",&str);
 close(q[0]);
 result=write(q[1],str,strlen(str)+1);
 if(result<0)
   printf("Pipewrite error");
 close(q[1]);
}

return 0;
}
