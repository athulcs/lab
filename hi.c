#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char tprint[1000]="ROOT/";
void scandir(char path[],int level,int maxlevel){
	int n,i,j;
	char npath[100];
	if(level < maxlevel){
		printf("Enter number of subdir in %s:",path);
		scanf("%d",&n);
		for(i=0;i<n;i++){
			sprintf(tprint,"%s\n|",tprint);
			for(j = 0;j<level;j++) 
	    			sprintf(tprint,"%s   ",tprint);
			sprintf(tprint,"%s---",tprint);
			sprintf(tprint,"%sDIR%d/",tprint,i+1);		
			sprintf(npath,"%sDIR%d/",path,i+1);
			scandir(npath,level+1,maxlevel);
		}
	}
	printf("Enter number of files in %s:",path);
	scanf("%d",&n);
	for(i=0;i<n;i++){
		sprintf(tprint,"%s\n|",tprint);
		for(j = 0;j<level;j++) 
    			sprintf(tprint,"%s   ",tprint);
		sprintf(tprint,"%s---",tprint);
		sprintf(tprint,"%sFILE%d",tprint,i+1);
	}
}
void main(){
	int op;
	do{
		sprintf(tprint,"%s","ROOT/");
		printf("\nMENU\n1.Single Level\n2.Two Level\n3.Hierarchical\n4.Exit\nEnter choice: ");
		scanf("%d",&op);
		char path[100] = "ROOT/";
		switch(op){
			case 1: scandir(path,0,0);
				break;
			case 2: scandir(path,0,1);
				break;
			case 3: scandir(path,0,10);
				break;
			case 4: break;
			default: printf("Invalid choice !!");
		}
		if(op!=4)
			printf("%s",tprint);
	}while(op != 4);
}
