#include<stdio.h>
void main(){
	int i,j,dfa[10][2],fin[10],n,count;
	printf("DFA has only 2 alphabets (1|0)\n");
	printf("------------------------------\n");
	printf("Enter the number of states:");
	scanf("%d",&n);
	for(i=0;i<n;i++){			//Inputting the DFA
		printf("(Q%d,0)=",i);
		scanf("%d",&dfa[i][0]);
		printf("(Q%d,1)=",i);
		scanf("%d",&dfa[i][1]);
		printf("Is Q%d final or not?(1/0):",i);
		scanf("%d",&fin[i]);
	}
	int myhill[n][n]; //Initialising minimisation table
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(j<i){
				if(fin[i]!=fin[j])
					myhill[i][j]=1;
				else
					myhill[i][j]=0;
			}
			else
				myhill[i][j]=-1;
		}
	}
	do{			//Completing table by checking transitions
		count=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(j<i&&myhill[i][j]==0){
					if((myhill[dfa[i][0]][dfa[j][0]]==1)||(myhill[dfa[i][1]][dfa[j][1]]==1)){
						myhill[i][j]=1;			
						count++;
					}
				}
			}
		}
	}while(count);

	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(j<i)
				printf("%d",myhill[i][j]);
		printf("\n");	
	}
}