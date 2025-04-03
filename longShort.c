#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Main takes 3 command line arguments: 
    // Filename to read + two filenames to write
int main(int argc, char *argv[]) {
    
    // Validate user input must have 3 arguments on the command line
    if (argc < 4) {
        printf("Must supply 3 arguments: Filename to read and two filenames to write!\n");
        exit(1);
    }

    // Open file for reading
    FILE *readFile = fopen(argv[1], "r");
    // Validate if filename exists
    if (readFile == NULL) {
        printf("%s not found!\n", argv[1]);
        exit(1);
    }

    // Open first filename for writing
    FILE *firstFile = fopen(argv[2], "w");
    // Validate file exists
    if (!firstFile) {
        printf("%s does not exists!\n", argv[2]);
        exit(1);
    }

    // Open second filename for writing
    FILE *secFile = fopen(argv[3], "w");
    // Validate file exists
    if (!secFile) {
        printf("%s does not exists!\n", argv[3]);
        exit(1);
    }

    // Read from the file using fgets, create array variable size enough to receive chars from line
    int firstFileC = 0, secFileC = 0;
    char line[100];
    while (fgets(line, 100, readFile) != NULL) {

        // Validate line if less than 20, write to first file
        if (strlen(line) < 20) {
            for (int i = 0; line[i] != '\0'; i++) {
                line[i] = toupper(line[i]);
            }
            fprintf(firstFile, "%s", line);
            firstFileC++;
        }
        // Validate line if more than 20, write to second file
        else {
            for (int i = 0; line[i] != '\0'; i++) {
                line[i] = tolower(line[i]);
            }
            fprintf(secFile, "%s", line);
            secFileC++;
        }
    }

    // Close all files
    fclose(readFile);
    fclose(firstFile);
    fclose(secFile);

    printf("%d lines written to %s\n", firstFileC, argv[2]);
    printf("%d lines written to %s\n", secFileC, argv[3]);

    return 0;

}