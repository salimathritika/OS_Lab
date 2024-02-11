//copied
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string1> <string2> ... <stringN>\n", argv[0]);
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        // Sort the strings
        int num_strings = argc - 1;
        char *sorted_strings[num_strings];

        // Copy the strings into a new array
        for (int i = 0; i < num_strings; i++) {
            sorted_strings[i] = argv[i + 1];
        }

        // Sort the array of strings
        for (int i = 0; i < num_strings - 1; i++) {
            for (int j = i + 1; j < num_strings; j++) {
                if (strcmp(sorted_strings[i], sorted_strings[j]) > 0) {
                    char *temp = sorted_strings[i];
                    sorted_strings[i] = sorted_strings[j];
                    sorted_strings[j] = temp;
                }
            }
        }

        // Display the sorted strings
        printf("Sorted strings:\n");
        for (int i = 0; i < num_strings; i++) {
            printf("%s\n", sorted_strings[i]);
        }

    } else { // Parent process
        // Wait for the child process to complete
        wait(NULL);

        // Display the unsorted strings
        printf("\nUnsorted strings:\n");
        for (int i = 1; i < argc; i++) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}
