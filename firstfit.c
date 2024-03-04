//works
#include <stdio.h>

void firstfit(int psize[],int n,int bsize[],int m)
{
int i,j;
int allocation[n];
for(i=0;i<n;i++)
allocation[i]=-1;

for(i=0;i<n;i++)
{
   for(j=0;j<m;j++)
      {
        if(bsize[j]>=psize[i])
           {
             allocation[i]=j;
             bsize[j]=bsize[j]-psize[i];
             break;
           }
      }
}

printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf(" %i\t\t\t", i+1); 
        printf("%i\t\t\t\t", psize[i]); 
        if (allocation[i] != -1) 
            printf("%i", allocation[i] + 1); 
        else
            printf("Not Allocated"); 
        printf("\n"); 
    } 

}

int main()
{
  int p[20],b[20],n,m,i;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  printf("Enter the process sizes:\n");
  for(i=0;i<n;i++)
    {
     printf("Process %d:",(i+1));
     scanf("%d",&p[i]);
    }
  printf("Enter the number of blocks:");
  scanf("%d",&m);
  printf("Enter the block sizes:\n");
  for(i=0;i<m;i++)
    {
     printf("Block %d:",(i+1));
     scanf("%d",&b[i]);
    }
  firstfit(p,n,b,m);
}
