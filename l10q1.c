//WORKS FOR FIFO
#include <stdio.h>
#include <stdlib.h>

int nframe,npage,front=0,rear=0;

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
   int i,j;
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
   fifo(pstr,fq,nframe,npage);
   
}
