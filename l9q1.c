//lab 9 question 1 works
#include<stdio.h>
#include<stdlib.h>

void display(int psize[],int n,int alloc[])
{
printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf(" %i\t\t\t", i+1); 
        printf("%i\t\t\t", psize[i]); 
        if (alloc[i] != -1) 
            printf("%i", alloc[i] + 1); 
        else
            printf("Not Allocated"); 
        printf("\n"); 
    } 
}


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
display(psize,n,allocation);

}

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
display(psize,n,allocation);

}

void worstfit(int psize[],int n,int bsize[],int m)
{
int i,j,k;
int allocation[n];
for(i=0;i<n;i++)
allocation[i]=-1;
for (i=0; i<n; i++) 
    { 
        int wstIdx = -1; 
        for (j=0; j<m; j++) 
        { 
            if (bsize[j] >= psize[i]) 
            { 
                if (wstIdx == -1) 
                    wstIdx = j; 
                else if (bsize[wstIdx] < bsize[j]) 
                    wstIdx = j; 
            } 
        } 
        if (wstIdx != -1) 
        { 
            allocation[i] = wstIdx;  
            bsize[wstIdx] -= psize[i]; 
        } 
    } 
display(psize,n,allocation);
}

int main()
{
  int n,m,i,opt;
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
  printf("Enter 1 for bestfit and 2 for first fit and 3 for worst fit allocation\n");
  scanf("%d",&opt);
  switch(opt)
  {
  case 1:{
          bestfit(p,n,b,m);
          break;
          }
  case 2:{
          firstfit(p,n,b,m);
          break;
          }
  case 3:{
          worstfit(p,n,b,m);
          break;
          }
  default:printf("Wrong choice\n");
  }
}

/*Enter the number of processes:4

Enter the process sizes:

Process 1:212

Process 2:417

Process 3:112

Process 4:426

Enter the number of blocks:5

Enter the block sizes:

Block 1:100

Block 2:500

Block 3:200

Block 4:300

Block 5:600

Enter 1 for bestfit and 2 for first fit and 3 for worst fit allocation

1



Process No.	Process Size	Block no.

 1			212			4

 2			417			2

 3			112			3

 4			426			5

*/
