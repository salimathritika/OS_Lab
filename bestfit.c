//works

#include <stdio.h>
#include<stdlib.h>

void bestfit(int psize[],int n,int bsize[],int m)
{
int i,j,k;
int allocation[n];
for(i=0;i<n;i++)
allocation[i]=-1;
for (i = 0; i < n; i++)  
    {    
        int bestIdx = -1;  
        for (j = 0; j < m; j++)  
        {  
            if (bsize[j] >= psize[i])  
            {  
                if (bestIdx == -1)  
                    bestIdx = j;  
                else if (bsize[bestIdx] > bsize[j])  
                    bestIdx = j;  
            }  
        }  
   
        if (bestIdx != -1)  
        {  
            allocation[i] = bestIdx;    
            bsize[bestIdx] -= psize[i];  
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
  int n,m,i;
  printf("Enter the number of processes:");
  scanf("%d",&n);
  int *p=(int*)malloc(sizeof(int)*n);
  printf("Enter the process sizes:\n");
  for(i=0;i<n;i++)
    {
     printf("Process %d:",(i+1));
     scanf("%d",&p[i]);
    }
  printf("Enter the number of blocks:");
  scanf("%d",&m);
  int *b=(int*)malloc(sizeof(int)*m);
  printf("Enter the block sizes:\n");
  for(i=0;i<m;i++)
    {
     printf("Block %d:",(i+1));
     scanf("%d",&b[i]);
    }
  bestfit(p,n,b,m);
}
