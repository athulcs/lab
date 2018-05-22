#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int main(int argc,char *argv[]){
	char bin[20];
	int before=0,i;
	float after=0;
	strcpy(bin,argv[1]);
	char *token = strtok(bin, ".");
    int bin_num=atoi(token);
    	for(i=0;bin_num>0;i++){
        	before+=(bin_num%10)*pow(2,i);
        	bin_num=bin_num/10;
        }
    token = strtok(NULL, ".");
    i=strlen(token)*-1;
    bin_num=atoi(token);
     
    for(i;bin_num>0;i++){
        after+=(bin_num%10)*pow(2,i);
        bin_num=bin_num/10;
    }

    printf("Decimal value is %f \n",before+after);
	return 0;
}