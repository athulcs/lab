#include <stdio.h>
void main(){
	int n,m,b,i;
	printf("Enter the number of objects:");
	scanf("%d",&n);
	int v[n],w[n],x[n];
	float r[n];
	printf("Enter the value and weight pairs of the objects:\n");
	for(i=0;i<n;i++)
		scanf("%d %d",&v[i],&w[i]);		
	printf("Enter the capacity of knapsack:");
	scanf("%d",&m);
	for(i=0;i<n;i++){					//Initialising ratio
		x[i]=0;
		r[i]=v[i]/w[i];
	}
	for(i=0;i<n;i++){
		b=m;
		if (w[i] >b)
			break;
		x[i]=1;
		b=b-w[i];
	}
	if(i<=n)
		x[i]=b/w[i];
	printf("The answer is %d\n",x[i]);
}