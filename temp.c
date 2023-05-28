#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main() {
    FILE *file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    char line[MAX_LENGTH];
    char *token;
    
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        if (token != NULL) {
            printf("First column value: %s\n", token);
        }
    }

    fclose(file);
    return 0;
}