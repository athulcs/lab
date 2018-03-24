#include<stdio.h>
void main(){
	int i,j,k,n,a,count;
	//printf("DFA has only 2 alphabets (1|0)\n");
	printf("------------------------------\n");
	printf("Enter the number of states:");
	scanf("%d",&n);
	printf("Enter the number of alphabets:");
	scanf("%d",&a);
	int dfa[n][a],fin[n];
	for(i=0;i<n;i++){		//Inputting the DFA
		for(j=0;j<a;j++){	
			printf("(Q%d,%d)=",i,j);
			scanf("%d",&dfa[i][j]);
		}
		printf("Is Q%d final or not?(1/0):",i);
		scanf("%d",&fin[i]);
		printf("\n");
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
					for(k=0;k<a;k++){
						if(myhill[dfa[i][k]][dfa[j][k]]==1){
							myhill[i][j]=1;			
							count++;
							break;
						}
					}
					
				}
			}
		}
	}while(count);

/*	for(i=0;i<n;i++){
			for(j=0;j<n;j++)
				if(j<i)
				printf("%d",myhill[i][j]);
			printf("\n");
		}
*/
	int states=0;		//Grouping unmarked positions in table
	int min[n];
	for(i=0;i<n;i++)
		min[i]=-1;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			if(j<i&&myhill[i][j]==0&&min[i]<0&&min[j]<0){
				min[i]=states;
				min[j]=states;
				for(k=i;k<n;k++)
					if(myhill[k][j]==0)
						min[k]=states;
				states++;		
			}
		}
		states--;
			while(states>=0){
				for(i=0;i<n;i++){
					if(min[i]==states)
					printf("Q%d,",i);
				}
				printf("can be grouped together.\n");
				states--;
			}
	printf("------------------------------\n");
}