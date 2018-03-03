#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main(){
 pid_t pid1;
 pid1 = fork();
 if(pid1){
    int fd;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char str1[80], str2[80];
    printf("Enter the message to be sent from P1: ");
    fd = open(myfifo, O_WRONLY);
    fgets(str2, 80, stdin);
    write(fd, str2, strlen(str2)+1);
    close(fd);
    fd = open(myfifo, O_RDONLY);
    read(fd, str1, sizeof(str1));
    printf("Message from P2: %s", str1);
    close(fd);    
  }
  else{
    int fd1;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char str1[80], str2[80];
    fd1 = open(myfifo,O_RDONLY);
    read(fd1, str1, 80);
    printf("Message from P1: %s", str1);
    close(fd1);
    fd1 = open(myfifo,O_WRONLY);
    printf("Enter the message to be sent from P2: ");
    fgets(str2, 80, stdin);
    write(fd1, str2, strlen(str2)+1);
    close(fd1);
  }
  return 0;
}