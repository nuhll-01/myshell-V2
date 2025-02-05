#include "headers.h"

int count(FILE* file_pointer) { 
    char line[MAX];
    int numberOfLines = 0;
    while (fgets(line, sizeof(line), file_pointer)) {
        numberOfLines++;
    }
    return numberOfLines;
}

void printHead(FILE* file_pointer) { 
    char line[MAX];
    for (int i = 0; i < 3; i++) { 
        fgets(line, sizeof(line), file_pointer);
        printf("%s", line);
    }
}

void print(FILE* file_pointer) { 
    char line[MAX];
    while (fgets(line, sizeof(line), file_pointer)) { 
        printf("%s", line);
    }
}

void file_rewind(FILE* file_pointer) { 
    fseek(file_pointer, 0, SEEK_END);
    rewind(file_pointer);
}

int main(int argc, char *argv[]) {
    int numberOfLines = 0;
    const char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) { 
        fprintf(stderr, "Error: failed to open file\n");
        return -1;
    }

    // determine the number of lines
    numberOfLines = count(fp);

    // rewind the buffer
    file_rewind(fp);

    if (numberOfLines > 3) {
        printHead(fp);
    } else {
        print(fp);
    }

    fclose(fp);
    
    return 0;
}
