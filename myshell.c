#include "headers.h"

char **createArray(int size) {
    char **ptr = calloc(size, sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Error: memory allocation failed\n");
        exit(1);
    }
    return ptr;
}

int main(int argc, char *argv[]) { 
    char input[30];
    char program[30];
    char file1[15];
    char file2[15];
    char *token;
    pid_t pid;

    if (argc > 1) { 
        fprintf(stderr, "Error: Too many arguments\n");
        return -1;
    }

    while(1) { 
        printf("%s", "myshell> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = 0; // remove the trailing new line from the input
        token = strtok(input, " "); // store the first token (which would be the name of the command)
    
        // commands
        if (strcmp(token, CAT) == 0) {
            // todo
            snprintf(program, sizeof(program), "./%s", token);

            // intialize array to store files
            char **arr = createArray(CATSIZE);
        
            // store the files in the array
            int index = 0;
            while (token != NULL) {
                token = strtok(NULL, " ");
                arr[index] = token;
                index++;
            }

            // determine the number of files
            int file_count = (arr[0] != 0) + (arr[1] != 0);

            if (file_count == 0) { 
                printf("%s\n", "insufficient number of arguments.");
            }

            if (file_count > 0) { 
                snprintf(file1, sizeof(file1), "%s", arr[0]); 

                if (file_count == 2) {
                    snprintf(file2, sizeof(file2), "%s", arr[1]);
                }

                pid = fork();

                if (pid == 0) {
                    char *args[] = {program, file1, (file_count == 2) ? file2 : NULL, NULL};
                    execvp(args[0], args);
                }

                waitpid(pid, NULL, 0);
            }

        } else if (strcmp(token, HEAD) == 0) { 
            // todo
            snprintf(program, sizeof(program), "./%s", token);
            pid = fork();
            if (pid == 0) { 
                char *args[] = {program, NULL};
                execvp(args[0], args);
            }
            waitpid(pid, NULL, 0);
        } else if (strcmp(token, UNIQ) == 0) { 
            // todo
            snprintf(program, sizeof(program), "./%s", token);
            pid = fork();
            if (pid == 0) { 
                char *args[] = {program, NULL};
                execvp(args[0], args);
            }
            waitpid(pid, NULL, 0);
        } else if (strcasecmp(token, EXIT) == 0) { 
            break;
        } else { 
            printf("%s\n", "command not found.");
        }
    }

    return 0;
}
