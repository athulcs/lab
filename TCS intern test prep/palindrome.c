#include <stdio.h>
#include <string.h>

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}

int main(int argc,char *argv[]){
	printf("You have Entered %d arguments:\n",argc);
	for(int i=0;i<argc;i++)
		printf("%s\n",argv[i]);
	int len;
	int count=1;
	char str[20];
	while(count<argc){
	len=strlen(argv[count]);
	strcpy(str,argv[count]);
	strrev(str);
	if(strcmp(str,argv[count])==0)
		printf("Is palindrome\n");
	else
		printf("Not a palindrome\n");
	count++;
}
	return 0;
}