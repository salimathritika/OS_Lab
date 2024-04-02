//WORKS FOR FIFO AND OPTIMAL
#include <stdio.h>
#include <stdlib.h>

int nframe,npage;

void optimal(int *pstr,int *fq,int nframe,int npage)
{
int flag1, flag2, flag3, i, j, k, position, max, faults = 0;
int temp[nframe];
printf("Page\t\tFrames\n");
for(i = 0; i < npage; i++){     
      flag1 = flag2 = 0;
        for(j = 0; j < nframe; j++){
            if(fq[j] == pstr[i]){
                   flag1 = flag2 = 1;
                   break;
               }
        }
        if(flag1 == 0){
            for(j = 0; j < nframe; j++){
                if(fq[j] == -1){
                    faults++;
                    fq[j] = pstr[i];
                    flag2 = 1;
                    break;
                }
            }    
        }
        if(flag2 == 0){
            flag3 =0;
            for(j = 0; j < nframe; j++){
                temp[j] = -1;
                for(k = i + 1; k < npage; k++){
                    if(fq[j] == pstr[k]){
                        temp[j] = k;
                        break;
                    }
                }
            }
            for(j = 0; j < nframe; j++){
                if(temp[j] == -1){
                    position = j;
                    flag3 = 1;
                    break;
                }
            }
            if(flag3 ==0){
                max = temp[0];
                position = 0;
                for(j = 1; j < nframe; j++){
                    if(temp[j] > max){
                        max = temp[j];
                        position = j;
                    }
                }               
            }
            fq[position] = pstr[i];
            faults++;
        }
        printf("\n");
        printf("%d\t\t",pstr[i]);
        for(j = 0; j < nframe; j++){
            printf("%d\t", fq[j]);
        }
    }
    printf("\n\nTotal Page Faults = %d", faults);
    printf("\nHits ratio = %d/%d\n", (npage-faults),npage);
}

void fifo(int *pstr,int *fq,int nframe,int npage)
{
   int i,j,flag=0,a=0,fault=0;
   printf("Page\t\tFrames\n");
   for(i=0;i<npage;i++)
   {
     flag=0;
     printf("%d\t\t",pstr[i]);
     for(j=0;j<nframe;j++)
        {
          if(pstr[i]==fq[j])
             flag=1;
        }
     if(flag==0)
       { 
         fq[a]=pstr[i];
         a=(a+1)%nframe;
         fault++;
         for(j=0;j<nframe;j++)
            printf("%d\t",fq[j]);
       }
     printf("\n");
   }
   printf("Number of faults=%d",fault);
   printf("\nHit ratio=%d/%d\n",(npage-fault),npage);
}

int main()
{
   int i,j,opt;
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
   printf("\nChoose one of the algorithms:\n1.FIFO\n2.Optimal\n");
   scanf("%d",&opt);
   switch(opt)
   {
   case 1:fifo(pstr,fq,nframe,npage);
          break;
   case 2:optimal(pstr,fq,nframe,npage);
          break;
   }
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



Choose one of the algorithms:

1.FIFO

2.Optimal

2

Page		Frames



3		3	-1	-1	

2		3	2	-1	

1		3	2	1	

3		3	2	1	

4		4	2	1	

1		4	2	1	

6		4	2	6	

2		4	2	6	

4		4	2	6	

3		4	2	3	

4		4	2	3	

2		4	2	3	

1		4	2	1	

4		4	2	1	

5		5	2	1	

2		5	2	1	

1		5	2	1	

3		3	2	1	

4		4	2	1	



Total Page Faults = 10

Hits ratio = 9/19
*/
