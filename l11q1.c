//SSTF SCAN C_SCAN C_LOOK WORKS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct 
{
	int reqtn;
	bool visited;
}request;

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
			if(abs(init - req[j].reqtn) < min && req[j].visited == false)
			{
				min = abs(init - req[j].reqtn);
				min_track_number = req[j].reqtn;
				pos = j;
			}
		}
		init = req[pos].reqtn;
		req[pos].visited = true;
		printf("%d ->",min_track_number);
		seek += min;
		i--;
	}
        printf("End");
	printf("\nSeek Time: %d\n", seek);
}

void scan(int nr, request * r, int head)
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
    printf("%d -> \n", limit-1);
 seek_time += 2*(limit - 1 - head); 
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



void c_scan(int nr, request * r, int head)
{
    int i, seek_time = 0;
    int limit;
    printf("Enter the cylinder size: ");
    scanf("%d", &limit);
    int cp_head=head;

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
    printf("%d -> \n", limit-1);
     
 seek_time += abs(limit - 1 - head); 
 head=0;
 seek_time += abs(limit -1 - head);
    // Head movement towards head
    for (i = head; i < cp_head; i++)
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

void c_look(int nr, request * r, int head)
{
    int i, seek_time = 0;
    int limit;
    printf("Enter the cylinder size: ");
    scanf("%d", &limit);
    int cp_head=head;

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
    int prev=head;
    
    int min = r[0].reqtn; // Initialize min with the first request
    for (int i = 1; i < nr; i++) {
        if (r[i].reqtn < min) {
            min = r[i].reqtn; // Update min if a smaller request is found
        }}


 head=min;
 seek_time += abs(prev - head);
    // Head movement towards head
    for (i = head; i < cp_head; i++)
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
   printf("1.SSTF\n2.SCAN\n3.C-SCAN\n4.C-LOOK\n");
   scanf("%d",&opt);   
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
	
   switch(opt)
   {
     case 1:
     {
       	sstf(init,req,n);
	break;
     }   
     case 2:
     {
        scan(n,req,init);
	break;
     } 
     case 3:
     {
        c_scan(n,req,init);
	break;
     } 
     case 4:
     {
        c_look(n,req,init);
	break;
     } 
     default: printf("\nInvalid entry\n");
}
}

/*
Choose one of the following algorithms:
1.SSTF
2.SCAN
3.C-SCAN
4.C-LOOK
1
Enter the number of requests: 8
Enter the requests: 176
79
34
60
92
11
41
114
Enter initial position of head: 50
50 -> 41 ->34 ->11 ->60 ->79 ->92 ->114 ->176 ->End
Seek Time: 204
*/

