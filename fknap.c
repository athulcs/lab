#include <stdio.h>
void main(){
	int n,m,b,i,j,tempv=0,tempw=0;
	printf("Enter the number of objects:");
	scanf("%d",&n);
	int v[n],w[n];
	float r[n],finvalue=0;
	printf("Enter the value and weight pairs of the objects.\n");
	for(i=0;i<n;i++)
		scanf("%d %d",&v[i],&w[i]);		
	printf("Enter the capacity of knapsack:");
	scanf("%d",&m);

	for(i=0;i<n;i++)					//Initialising ratio
		r[i]=v[i]/w[i];
	

	for(i=0;i<n;i++){					//Sorting according to ratio
		for(j=0;j<n-1;j++){
			if(r[j]<r[j+1]){
				tempv=v[j+1];
				tempw=w[j+1];
				v[j+1]=v[j];
				w[j+1]=w[j];
				w[j]=tempw;
				v[j]=tempv;
			}
		}
	}

	b=m;
	for(i=0;i<n;i++){					//Selecting objects  by checking overflow

		if (w[i] >b){
			finvalue+=v[i]*((float)b/w[i]);
			break;
		}
		else{
			b=b-w[i];
			finvalue+=v[i];
		}

	}
	
	printf("The maximum value is %.2f\n",finvalue);
}