//does not work
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>


int main()
{
int n;
printf("Enter the value of n");
scanf("%d",&n);
printf("Enter %d strings",n);
int i,j;
char *str[n];
for(i=0;i<n;i++)
scanf("%s",str[i]);
pid_t p1;
int status;
p1=fork();

if(p1==0)
{
char *bubble[n];
for(i=0;i<n;i++)
strcmp(bubble[i],str[i]);
char *temp;
for (i = 0; i < n- 1; i++) 
{
for (j = i + 1; j < n; j++) 
{
if (strcmp(bubble[i], bubble[j]) > 0) 
{
char *temp=bubble[i];
bubble[i]=bubble[j];
bubble[j]=temp;
//   strcmp(temp,bubble[i]);
//   strcmp(bubble[i],bubble[j]);
//  strcmp(bubble[j],temp);
}
}
}
printf("\nUsing bubble sort:\n");
for(i=0;i<n;i++)
printf("%s\t",bubble[i]);
printf("\n");
}
else if(p1>0)
wait(&status);
else
printf("\nForking failed\n");


}
