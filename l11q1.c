//FCFS AND SSTF WORKS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
	int request_track_number;
	bool visited;
}request;

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

/*
void scan(int init,int prev,request req[],int n,int limit)
{
  int choice,i,j;
  if(prev - init > 0 )
	{
		choice = 2;
	}
	else
		choice = 1;
	
	int seek=0;
	printf("%d -> ",init );
	if(choice == 1)
	{
		for(i=init;i<limit;i++)
		{
			for(j=0;j<n;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek += abs(req[j].request_track_number - init);
					init = req[j].request_track_number;
				}
			}
		}
		printf("%d -> ", limit-1);
		seek += abs(limit-1 - init);
		init = limit-1;
		for(i=init;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek += abs(req[j].request_track_number - init);
					init = req[j].request_track_number;
				}
			}
		}
		seek += abs(init - 0);
		printf("0 \n");
	}
	else if(choice == 2)
	{
		for(i=init;i>=0;i--)
		{
			for(j=0;j<n;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek += abs(req[j].request_track_number - init);
					init = req[j].request_track_number;
				}
			}
		}
		printf("%d -> ", 0);
		seek += abs(0 - init);
		init = 0;
		for(i=init;i<limit;i++)
		{
			for(j=0;j<n;j++)
			{
				if(req[j].request_track_number == i && req[j].visited == false)
				{
					printf("%d -> ", req[j].request_track_number);
					req[j].visited = true;
					seek += abs(req[j].request_track_number - init);
					init = req[j].request_track_number;
				}
			}
		}
		seek += abs(limit-1 - init );
		printf("%d \n", limit-1);
		
	}
	printf("Seek Time: %d\n", seek);
}
*/

int main()
{
   int i,n,init,opt,prev,limit;
   
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
       printf("Enter the number of requests: ");
	scanf("%d",&n);
	request req[n];
	printf("Enter the requests: ");
	for (i = 0; i < n; ++i)
	{
		scanf("%d",&req[i].request_track_number);
		req[i].visited = false;
	}
	printf("Enter initial position of head: ");
	scanf("%d",&init);

	printf("Enter the previous position of head: ");
	scanf("%d",&prev);

	printf("Enter the cylinder size: ");
	scanf("%d",&limit);
	scan(init,prev,req,n,limit);
	break;
     } 
}
}
