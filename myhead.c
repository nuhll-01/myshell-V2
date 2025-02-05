#include "headers.h"

/*
* count the total number of lines
*/
int count(FILE* file_pointer) { 
    char line[MAX];
    int numberOfLines = 0;
    while (fgets(line, sizeof(line), file_pointer)) {
        numberOfLines++;
    }
    return numberOfLines;
}

/*
* display the first three lines of the text file
*/
void printHead(FILE* file_pointer) { 
    char line[MAX];
    for (int i = 0; i < 3; i++) { 
        fgets(line, sizeof(line), file_pointer);
        printf("%s", line);
    }
}

/*
* display the "entire" text file
*/
void print(FILE* file_pointer) { 
    char line[MAX];
    while (fgets(line, sizeof(line), file_pointer)) { 
        printf("%s", line);
    }
}

/*
* set the cursor back to the beginning
*/
void file_rewind(FILE* file_pointer) { 
    fseek(file_pointer, 0, SEEK_END);
    rewind(file_pointer);
}


/*
* the main function
*/
int main(int argc, char *argv[]) {
    int numberOfLines = 0;
    const char* filename = argv[1];
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) { 
        fprintf(stderr, "Error: failed to open file\n");
        return -1;
    }

    numberOfLines = count(fp);

    file_rewind(fp);

    if (numberOfLines > 3) {
        printHead(fp);
    } else {
        print(fp);
    }

    fclose(fp);

    return 0;
}
