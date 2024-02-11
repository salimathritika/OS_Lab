//copied
#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        printf("Child process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Child process message: Hello from the child!\n");
    } else { // Parent process
        printf("Parent process: PID = %d, PPID = %d\n", getpid(), getppid());
        printf("Parent process message: Hello from the parent!\n");
    }

    return 0;
}
