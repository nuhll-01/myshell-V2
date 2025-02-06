#include "headers.h"
/**
 *  @brief The uniq-command driver function.
 *  
 *  @param argc total number of command-line arguments.
 *  @param argv array containing the command-line arguments.
 * 
 *  @returns 0 upon successful execution, -1 if unsucessful.
 * 
 */
int main(int argc, char* argv[]) {

    // check if there's only two arguments
    if (argc == 2) { 
        const char* filename = argv[1];
        
        FILE* fd = fopen(filename, "r");

        if (fd == NULL) { 
            fprintf(stderr, "Operation Failed.\nUnable to open: \"%s\"\n", filename);
            return -1;
        }

        char line[1024];
        char prevLine[1024] = "";

        // read and copy the first line 'prevLine' variable
        if (fgets(line, sizeof(line), fd)) { 
            strcpy(prevLine, line); // store the first line as previous
            printf("%s", line); // print the first line
        }

        // traverse through the rest of lines
        while (fgets(line, sizeof(line), fd)) { 
            // compare the current line with previous line
            // if current line does not equal to the previous then it's unique.
            if (strcmp(line, prevLine) != 0) { 
                printf("%s", line);
                strcpy(prevLine, line);
            }
        }

        fclose(fd);
    }

    return 0;
}
