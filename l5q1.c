//lab 5 question 1 working

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
pid_t p=fork();
if(p==0)
{
printf("This is the child process\n");
printf("PID=%d and PPID=%d\n",getpid(),getppid());
}
else if(p>0)
{
printf("This is the parent process\n");
printf("PID=%d and PPID=%d\n",getpid(),getppid());
}
else
printf("There was an error in forking");
}
