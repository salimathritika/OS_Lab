//lab 5 question 2 working

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>


int main(int argc, char *argv[])
{
if(argc==1)
{printf("No extra arguements passed");
return 0;
}
pid_t p;
int status;
p=fork();
if(p>0)
{
wait(&status);

printf("Unsorted list by the parent process\n");
for(int i=1;i<argc;i++)
printf("%s\t",argv[i]);
printf("\n");
}
else if(p==0)
{
printf("Sorted list by the child process:\n");
int num = argc - 1;
char *sorted[num];
for (int i = 0; i < num; i++) 
{
sorted[i] = argv[i + 1];
}
for (int i = 0; i < num - 1; i++) 
{
for (int j = i + 1; j < num; j++) 
{
if (strcmp(sorted[i], sorted[j]) > 0) 
{
   char *temp = sorted[i];
   sorted[i] = sorted[j];
   sorted[j] = temp;
}
}
}

for(int i=0;i<num;i++)
printf("%s\t",sorted[i]);
printf("\n");
}
else
{
printf("Error. Forking failed");
}
}
