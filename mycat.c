#include "headers.h"

/**
 *  @brief prints each individual line of the file
 *  
 *  @param file_pointer pointer to target file
 *
 */
void print(FILE* file_pointer) { 
    char line[MAX];
    while (fgets(line, sizeof(line), file_pointer)) { printf("%s", line); }
}

/**
 *  @brief The cat-command driver function.
 *  
 *  @param argc total number of command-line arguments.
 *  @param argv array containing the command-line arguments.
 * 
 *  @returns 0 upon successful execution, -1 if unsucessful.
 * 
 */
int main(int argc, char *argv[]) { 
    // todo
    if (argc == 2) { 
        const char* filename = argv[1];
        FILE* fp = fopen(filename, "r");

        if (fp == NULL) { 
            fprintf(stderr, "Error: failed to open file\n");
            return -1;
        }

        print(fp);
        fclose(fp);
    }

    if (argc == 3) { 
        const char* filename1 = argv[1];
        const char* filename2 = argv[2];

        FILE* fp1 = fopen(filename1, "r");
        FILE* fp2 = fopen(filename2, "r");

        if (fp1 == NULL || fp2 == NULL) { 
            fprintf(stderr, "Error: failed to open file\n");
            return -1;
        }

        print(fp1);
        print(fp2);

        fclose(fp1);
        fclose(fp2);
    }

    return 0;
}
