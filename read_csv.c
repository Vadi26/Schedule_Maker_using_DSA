#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *the_file = fopen("database.csv", "r");
    if (the_file == NULL) {
        perror("Unable to open the file :(");
        exit(1);
    }

    char line[200];

    while(fgets(line, sizeof(line), the_file)) {
        char *token;

        token = strtok(line, ",");

        while (token != NULL) {
            printf("%s", token);
            // In order to tokenize the remaining part of the line
            token = strtok(NULL, ",");
        }
        printf("\n");
    }
}