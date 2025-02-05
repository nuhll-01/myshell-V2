#include "headers.h"

void printLine(FILE* file_pointer) { 
    char line[MAX];
    while (fgets(line, sizeof(line), file_pointer)) { 
        printf("%s", line);
    }
}

int main(int argc, char *argv[]) { 
    // todo
    if (argc == 2) { 
        const char* filename = argv[1];
        FILE* fp = fopen(filename, "r");

        if (fp == NULL) { 
            fprintf(stderr, "Error: failed to open file\n");
            return -1;
        }

        // printing line-by-line
        printLine(fp);

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

        printLine(fp1);
        printLine(fp2);

        fclose(fp1);
        fclose(fp2);
    }

    return 0;
}
