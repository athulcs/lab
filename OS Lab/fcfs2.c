#include <stdio.h>

void main()
{	int sum,n,a,b,i,j;
	int at[10],bt[10],wt[10],tt[10];

 
	printf("enter the  no. of process");
	scanf("%d",&n);

	for(i=0;i<n;i++)
	{
 	printf("enter the arrival time");
 	scanf("%d",&at[i]);
 	printf("enter the burst time");
 	scanf("%d",&bt[i]);
	}

	for(i=0;i<n;i++)
	{	for(j=i+1;j<n;j++)
		{	if(at[i]>at[j])
			{a=at[i];
			at[i]=at[j];
			at[j]=a;
			b=bt[i];
			bt[i]=bt[j];
			bt[j]=b;
			}
		}
	}

	wt[0]=at[0];
	sum=bt[0];
	for(i=1;i<n;i++)
	{wt[i]=sum-at[i];
	sum=sum+bt[i];
	}
	
	for(i=0;i<n;i++)
	tt[i]=wt[i]+bt[i];

	printf("\nProcess_ID\tArrival_time\tBurst_time\tWaiting_time\tTuraround_time");
	
	for(i=0;i<n;i++)
		printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,at[i],bt[i],wt[i],tt[i]);

}

