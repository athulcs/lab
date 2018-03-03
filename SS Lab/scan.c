#include<stdio.h>
void main()
{
  int dp[10],temp,n,i,j,diff,head,pos,dloc;
  printf("Enter the no. of process in queue: ");
  scanf("%d",&n);
  printf("Enter the intial position of diskhead: ");
  scanf("%d",&head);
  printf("Enter the disk process: \n");
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
  printf("0");
  for(i=dloc+1;i<n;i++)
    printf("-->%d",dp[i]);

  printf("\nTotal distance seeked: %d\n",dp[n-1]+head);
}

