//FCFS SSTF WORKS
//SCAN is logically wrong i think
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
	int request_track_number;
	bool visited;
}request;

int absoluteValue(int x)
{
    if(x>0)
    {
        return x;
    }
    else
    {
        return x*-1;
    }
}

int fcfs(int init,int req[],int n)
{
   int i,seek=0;
   printf("Using FCFS:");
   printf("\n%d->",init);
   for(i=0;i<n;i++)
   {
      if(req[i]==req[n-1])
        printf("%d\n",req[i]);
      else
         printf("%d->",req[i]);
      seek+=abs(init-req[i]);
      init=req[i];
   }
   printf("\nSeek Time:%d\n",seek);
}

void sstf(int init,request req[],int n)
{
  int seek=0;
	printf("%d -> ",init );
	int i = n;
	while(i)
	{
		int min = 1e9;
		int min_track_number, pos;
		for(int j=0;j<n;j++)
		{
			if(abs(init - req[j].request_track_number) < min && req[j].visited == false)
			{
				min = abs(init - req[j].request_track_number);
				min_track_number = req[j].request_track_number;
				pos = j;
			}
		}
		init = req[pos].request_track_number;
		req[pos].visited = true;
		printf("%d ->",min_track_number);
		seek += min;
		i--;
	}
        printf("End");
	printf("\nSeek Time: %d\n", seek);
}

void scan(int init,int n,int max)
{
    int queue[25],i,j,k,difference,temp,queue1[20],queue2[20],temp1=0,temp2=0,seek=0;
    float averageSeekTime;
    printf("Enter the disk positions to be read(queue): ");
    for(i=1;i<=n;i++)   
    {
        scanf("%d",&temp);         
        
        if(temp>init)
        {
            queue1[temp1]=temp; 
            temp1++; 
        }
        else    
        {   
            queue2[temp2]=temp; 
            temp2++;
        }
    }
    
    for(i=0;i<temp1-1;i++)
    {
        for(j=i+1;j<temp1;j++)
        {
            if(queue1[i]>queue1[j])
            {
                temp=queue1[i];
                queue1[i]=queue1[j];
                queue1[j]=temp;
            }
        }
    }
    
    for(i=0;i<temp2-1;i++)
    {
        for(j=i+1;j<temp2;j++)
        {
            if(queue2[i]<queue2[j])
            {
                temp=queue2[i];
                queue2[i]=queue2[j];
                queue2[j]=temp;
            }
        }
    }    
    
    for(i=1,j=0;j<temp1;i++,j++)
    {
        queue[i]=queue1[j]; 
    }
    
    queue[i]=max;
    
    for(i=temp1+2,j=0;j<temp2;i++,j++)
    {
        queue[i]=queue2[j];
    }
    
    queue[i]=0;
 
    queue[0]=init;
    
    
    for(j=0; j<=n; j++) 
    {   
        
        difference = absoluteValue(queue[j+1]-queue[j]);
        seek = seek + difference;
        
        printf("Disk head moves from position %d to %d with Seek %d \n",
        queue[j], queue[j+1], difference);
    }
    
    averageSeekTime = seek/(float)n;
    
    printf("Total Seek Time= %d\n", seek);
    printf("Average Seek Time= %f\n", averageSeekTime);

}


int main()
{
   int i,n,init,opt,prev,limit,maxrange;
   
   printf("\nChoose one of the following algorithms:\n");
   printf("1.FCFS\n2.SSTF\n3.SCAN\n");
   scanf("%d",&opt);
   switch(opt)
   {
     case 1:
     {printf("Enter the number of requests:");
      scanf("%d",&n);
      printf("Enter the head:");
      scanf("%d",&init);
      int *req=malloc(sizeof(int)*n);
      for(i=0;i<n;i++)
         scanf("%d",&req[i]);
      fcfs(init,req,n);
      break;
     }
     case 2:
     {
       printf("Enter the number of requests: ");
	scanf("%d",&n);
	request *req=malloc(sizeof(request)*n);
	printf("Enter the requests: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&req[i].request_track_number);
		req[i].visited = false;
	}
	printf("Enter initial position of head: ");
	scanf("%d",&init);
	sstf(init,req,n);
	break;
     }   
     case 3:
     {
       printf("Enter the maximum range of Disk: ");
    scanf("%d",&maxrange);
    
    printf("Enter the number of queue requests: ");
    scanf("%d",&n);
    
    printf("Enter the initial head position: ");
    scanf("%d",&init);
    
    scan(init,n,maxrange);
	break;
     } 
}
}
