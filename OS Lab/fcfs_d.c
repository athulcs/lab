#include<stdio.h>
void main()
{
	int dp[10],n,i,diff,head,dist=0;
	printf("Enter the no. of process in queue:");
	scanf("%d",&n);
	printf("Enter the disk process:");
	for(i=0;i<n;i++)
		scanf("%d",&dp[i+1]);
	printf("Enter the intial position of diskhead:");
	scanf("%d",&head);
	dp[0]=head;
	for(i=0;i<n;i++)
	{	diff=abs(dp[i+1]-dp[i]);
		printf("The disk head moves from %d to %d -> %d\n",dp[i],dp[i+1],diff);
		dist=dist+diff;		
	}
	printf("Total distance seeked :%d\n",dist);
}