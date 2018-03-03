#include<stdio.h>
#include<stdbool.h>

int main() {
	int i,j,k,pcount=0,nr,np,need[5][5],alloc[5][5],max[5][5],avail[5], seq[5];
	bool finish[5]={false,false,false,false,false},flag=true,endflag=true; 
	printf("Enter the number of processes: ");
	scanf("%d",&np);
	printf("Enter the number of resource types\n");
	scanf("%d",&nr);
	printf("Enter the current allocation for each process\n");
	for(i=0;i<np;i++) {
		printf("Process %d\n",i+1);
		for(j=0;j<nr;j++) {
			scanf("%d",&alloc[i][j]);
		}		
	}
	printf("Enter the maximum of each resource required for each process\n");
	for(i=0;i<np;i++) {
		printf("Process %d\n",i+1);
		for(j=0;j<nr;j++) {
			scanf("%d",&max[i][j]);
			need[i][j] = max[i][j] - alloc[i][j];
		}		
	}
	printf("Enter the total available resources\n");
	for(i=0;i<nr;i++) {
		printf("Resource %d\n",i+1);
		scanf("%d",&avail[i]);
	}

	while(pcount<np) {
		flag=false;
		for(i=0;i<np;i++) {
			if(finish[i] == false) {
				for(j=0;j<nr;j++) {
					if(need[i][j] > avail[j]) {
						break;
					}
				}
				if(j == nr) {
					for(k=0;k<nr;k++) {
						avail[k] += alloc[i][k];
					}
					seq[pcount++] = i;
					finish[i] = true;
					flag=true;
				}	
			}	
		}
	}
	if(flag) {
		printf("System is in safe state\n");
		printf("Safe sequence is: \n");
		for(i=0;i<np-1;i++) {
			printf("%d -> ",seq[i]);
		}
		printf("%d\n",seq[i]);
	}
	else {
		printf("System is not in safe state\n");
	}
}