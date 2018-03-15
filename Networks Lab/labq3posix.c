#include <stdio.h>
#include <sys/msg.h>
#include <unistd.h>
#include <fcntl.h> 
#include <sys/stat.h> 
#include <mqueue.h> 


int main()
{   mqd_t mqp2;
   struct mq_attr attr; 
   attr.mq_flags = 0; 
   attr.mq_maxmsg = 10; 
   attr.mq_msgsize = 20; 
   attr.mq_curmsgs = 0; 
	pid_t pid1;
    pid1=fork();
    if(pid1){
        char str[20];
        mqp2 = mq_open ("/msgq", O_WRONLY);
        printf("Write Data : ");
        fgets(str,20,stdin);
        mq_send (mqp2,str, sizeof(str), 0);
      
    }
    else{
    	mqd_t mqp2;
    	struct mq_attr attr; 
	    attr.mq_flags = 0; 
	    attr.mq_maxmsg = 10; 
	    attr.mq_msgsize = 20; 
	    attr.mq_curmsgs = 0;
        char str[20];
        mqp2 = mq_open ("/msgq", O_RDONLY | O_CREAT,0666, &attr);
        mq_receive (mqp2,str,sizeof(str), NULL);
        printf("Data Received is : %s",str);
       
    }
 
    return 0;
}