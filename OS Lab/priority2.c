#include<stdio.h>
void main()
{
int n,p[10],pt[10],bt[10],wt[10],tt[10],temp,temp1,sum,i,j,pos;
printf("Enter the no. of process\n");
scanf("%d",&n);
for(i=0;i<n;i++)
	{printf("Enter the process P[%d]'s burst time:",i+1);
	scanf("%d",&bt[i]);
	printf("Enter the process P[%d]'s priority:",i+1);
	scanf("%d",&pt[i]);
	p[i]=i+1;
	}
for(i=0;i<n;i++)
{	pos=i;
	for(j=i+1;j<n;j++)
		{if(pt[pos]>pt[j])
			pos=j;	
		}		
		temp=pt[i];
		pt[i]=pt[pos];
		pt[pos]=temp;

		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;

		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;	
}
sum=bt[0];
wt[0]=0;
for(i=1;i<n;i++)
	{	wt[i]=sum;
		sum=sum+bt[i];
	}	
for(i=0;i<n;i++)		
		tt[i]=wt[i]+bt[i];	
printf("Process_ID\t|Priority\t|Burst_time\t|Waiting_time\t|Turnaround_time\n");
for(i=0;i<n;i++)
	printf("p[%d]\t\t|%d\t\t|%d\t\t|%d\t\t|%d\n",p[i],pt[i],bt[i],wt[i],tt[i]);
}