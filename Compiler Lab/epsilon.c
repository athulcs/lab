#include <stdio.h>
int n;

void check(int a[][n],int k){
	int i=0;
	for(i=0;i<n;i++){
	if(a[k][i] & (1 << 0)){
		printf("Q%d,",i);
		check(a,i);
	}
	else
		return;
}
	
}

void main(){
	int i,j,temp;
	printf("Enter the number of states:");
	scanf("%d",&n);
	int a[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Transition for State Q%d --> Q%d:",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<n;i++){
		printf("Epsilon transition of Q%d=Q%d,",i,i);
		for(j=1;j<n;j++){
			if(a[i][j] & (1 << 0)){
				printf("Q%d,",j);
				check(a,j);
			}
		}
		printf("\n");
	}
}