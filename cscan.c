#include<stdio.h>
void main()
{
  int dp[10],temp,n,i,j,diff,head,pos,dloc,max,min;
  printf("Enter the no. of process in queue: ");
  scanf("%d",&n);
  printf("Enter the intial position of diskhead: ");
  scanf("%d",&head);
  printf("Enter the starting position of disk: ");
  scanf("%d",&min);
  printf("Enter the limit of disk: ");
  scanf("%d",&max);
  printf("Enter the disk processes: \n");
  for(i=0;i<n;i++)
    scanf("%d",&dp[i]);
  dp[n]=head;
  n=n+1;
  for(i=0;i<n;i++)
    { for(j=i+1;j<n;j++)
        if (dp[i]>dp[j])
      { temp=dp[i];
        dp[i]=dp[j];
        dp[j]=temp;
      }
    }
  for(i=0;i<n;i++)   
    { if(head==dp[i]) 
      { dloc=i;
        break;  
      }
    }
  printf("\nDisk Path: ");
  for(i=dloc;i>=0;i--)
    printf("%d-->",dp[i]);
  printf("%d-->%d",min,max);
  for(i=n-1;i>dloc;i--)
    printf("-->%d",dp[i]);
  printf("\nTotal distance seeked: %d\n",abs(max-dp[dloc+1])+head);
}
