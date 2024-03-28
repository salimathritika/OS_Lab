/*#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int N, char *argv[])
{
int i,j,min,status;
char *temp;
//char mins[40];
pid_t pid1=fork();

if(pid1==0)
{
printf("In child process\n");
for(i=1;i<N;i++)
{
for(j=1;j<N-i;j++)
{
if(strcmp(argv[j],argv[j+1])>0)
{
strcpy(temp,argv[j]);
strcpy(argv[j],argv[j+1]);
strcpy(argv[j+1],temp);
}
}
}

printf("The bubble sorted strings are: ");
for(i=1;i<N;i++)
{
printf("%s\t",argv[i]);
}
printf("\n");

}

else if(pid1>0)
{
wait(&status);
pid_t pid2=fork();

if(pid2==0)
{
for(i=1;i<N-1;i++)
{
min=i;
//strcpy(mins,arv[i]);
for(j=i+1;j<N;j++)
{
if(strcmp(argv[j],argv[min])<0)
{
min=j;
}
temp=argv[min];
argv[min]=argv[i];
argv[i]=temp;
}
}
printf("The selection sorted strings are: ");
for(i=1;i<N;i++)
{
printf("%s\t",argv[i]);
}
printf("\n");


}
else
{
wait(&status);
printf("In parent process\n");
}

}
}
*/
#include <stdio.h>
#include <stdlib.h> // for malloc
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main(int N, char *argv[]) {
    int i, j, min, status;
    char *temp = NULL; // Initialize temp to NULL

    pid_t pid1 = fork();

    if (pid1 == 0) {
        printf("In child process\n");
        for (i = 1; i < N; i++) {
            for (j = 1; j < N - i; j++) {
                if (strcmp(argv[j], argv[j + 1]) > 0) {
                    temp = malloc(strlen(argv[j]) + 1); // Allocate memory for temp
                    strcpy(temp, argv[j]);
                    strcpy(argv[j], argv[j + 1]);
                    strcpy(argv[j + 1], temp);
                    free(temp); // Free allocated memory
                }
            }
        }

        printf("The bubble sorted strings are: ");
        for (i = 1; i < N; i++) {
            printf("%s\t", argv[i]);
        }
        printf("\n");
    } else if (pid1 > 0) {
        wait(&status);
        pid_t pid2 = fork();

        if (pid2 == 0) {
            for (i = 1; i < N - 1; i++) {
                min = i;
                for (j = i + 1; j < N; j++) {
                    if (strcmp(argv[j], argv[min]) < 0) {
                        min = j;
                    }
                }
                // Swap pointers
                temp = argv[min];
                argv[min] = argv[i];
                argv[i] = temp;
            }
            printf("The selection sorted strings are: ");
            for (i = 1; i < N; i++) {
                printf("%s\t", argv[i]);
            }
            printf("\n");
        } else {
            wait(&status);
            printf("In parent process\n");
        }
    }
    return 0;
}
