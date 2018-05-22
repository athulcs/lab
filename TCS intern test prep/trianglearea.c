#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	float s=0;
	int a=atoi(argv[1]);
	int b=atoi(argv[2]);
	int c=atoi(argv[3]);
	printf("%d %d %d\n",a,b,c);
	s=(a+b+c)/2;
	float area= sqrt(s*(s-a)*(s-b)*(s-c));
	printf("Area is %f\n",area);
	return 0;
}