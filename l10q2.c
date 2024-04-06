#include<stdio.h>
#include <stdlib.h>

int nframe,npage;

int main()
{
   int i,m, n, position, k, l;
    int a = 0, b = 0, page_fault = 0;
   printf("Enter the number of frames:");
   scanf("%d",&nframe);
   printf("Enter the number of pages:");
   scanf("%d",&npage);
   int *fq=malloc(sizeof(int)*nframe);
   int *pstr=malloc(sizeof(int)*npage);
   printf("Enter the string of pages:\n");
   for(i=0;i<npage;i++)
      scanf("%d",&pstr[i]);
   for(i=0;i<nframe;i++)
      fq[i]=-1;
    
    int temp[nframe];
    
    for(n = 0; n < npage; n++)
    {
        
            a = 0, b = 0;
            for(m = 0; m < nframe; m++)
            {
                if(fq[m] == pstr[n])
                {
                        a = 1;
                        b = 1;
                        break;
                }
            }
            if(a == 0)
            {
                for(m = 0; m < nframe; m++)
                {
                    if(fq[m] == -1)
                    {
                        fq[m] = pstr[n];
                        b = 1;
                        page_fault++;
                        break;
                    }
                }
            }
            if(b == 0)
            {
                for(m = 0; m < nframe; m++)
                {
                    temp[m] = 0;
                }
                for(k = n - 1, l = 1; l <= nframe - 1; l++, k--)
                {
                    for(m = 0; m < nframe; m++)
                    {
                        if(fq[m] == pstr[k])
                        {
                            temp[m] = 1;
                        }
                    }
                }
                for(m = 0; m < nframe; m++)
                {
                    if(temp[m] == 0)
                        position = m;
                }
                fq[position] = pstr[n];
                page_fault++;
            }
            printf("%d: ", pstr[n]);
            
            for(m = 0; m < nframe; m++)
            {
                printf("%d\t", fq[m]);
            }
            printf("\n");
    }
    printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
    printf("Hit ratio: %d/%d\n",(npage-page_fault),npage);
    
    return 0;
}


/*
Enter the number of frames:3
Enter the number of pages:19
Enter the string of pages:
3
2
1
3
4
1
6
2
4
3
4
2
1
4
5
2
1
3
4
3: 3	-1	-1	
2: 3	2	-1	
1: 3	2	1	
3: 3	2	1	
4: 3	4	1	
1: 3	4	1	
6: 6	4	1	
2: 6	2	1	
4: 6	2	4	
3: 3	2	4	
4: 3	2	4	
2: 3	2	4	
1: 1	2	4	
4: 1	2	4	
5: 1	5	4	
2: 2	5	4	
1: 2	5	1	
3: 2	3	1	
4: 4	3	1	

Total Number of Page Faults:	14
Hit ratio: 5/19
*/

