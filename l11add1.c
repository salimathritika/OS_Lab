//FCFS LOOK WORKS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
	int reqtn;
	bool visited;
}request;


void fcfs(int init,int req[],int n)
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

void look(int nr, request * r, int head)
{
    int i, seek_time = 0;
    int limit;
    printf("Enter the cylinder size: ");
    scanf("%d", &limit);

    printf("%d -> ", head);

    // Head movement towards larger track numbers
    for (i = head; i < limit; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            if (r[j].reqtn == i && r[j].visited == false)
            {
                printf("%d -> ", r[j].reqtn);
                r[j].visited = true;
                seek_time += abs(r[j].reqtn - head);
                head = r[j].reqtn;
            }
        }
    }
 
    // Head movement towards smaller track numbers
    for (i = limit - 1; i >= 0; i--)
    {
        for (int j = 0; j < nr; j++)
        {
            if (r[j].reqtn == i && r[j].visited == false)
            {
                printf("%d -> ", r[j].reqtn);
                r[j].visited = true;
                seek_time += abs(r[j].reqtn - head);
                head = r[j].reqtn;
            }
        }
    }

    printf("\nSeek Time: %d\n", seek_time);
}

int main()
{

  int i,n,init,opt;
  printf("\nChoose one of the following algorithms:\n");
   printf("1.FCFS\n2.LOOK\n");
   scanf("%d",&opt);
  if(opt==1)
   {
     printf("Enter the number of requests:");
      scanf("%d",&n);
      printf("Enter the requests\n");
      int *req=malloc(sizeof(int)*n);
      for(i=0;i<n;i++)
         scanf("%d",&req[i]);
      printf("Enter the head:");
      scanf("%d",&init);    
      fcfs(init,req,n);
   }
   
   else if(opt==2)
   {
     printf("Enter the number of requests: ");
	scanf("%d",&n);
	request *req=malloc(sizeof(request)*n);
	printf("Enter the requests: ");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&req[i].reqtn);
		req[i].visited = false;
	}
	printf("Enter initial position of head: ");
	scanf("%d",&init);
	look(n,req,init);
   }
   
}

/*
Choose one of the following algorithms:
1.FCFS
2.LOOK
1
Enter the number of requests:8
Enter the requests
176
79
34
60
92
11
41
114
Enter the head:50
Using FCFS:
50->176->79->34->60->92->11->41->114

Seek Time:510
*/
