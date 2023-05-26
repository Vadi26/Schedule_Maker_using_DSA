#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char line[200] = "AC-101,Monday,08:00-09:00,AmanJhinga,PSQT,FY_MT";
    char *token = strtok(line, ",");
    while (token) {
        printf("%s \n", token);
        token = strtok(NULL, ",");
    }
    return 0;
}

// #define MAX_ROWS 1000
// #define MAX_COLS 6
// #define MAX_STRING_LENGTH 100

// int main() {
//     FILE *csv_file = fopen("database.csv", "r");
//     if (csv_file == NULL) {
//         perror("Unable to open the file :(");
//         exit(1);
//     }

//     char line[MAX_STRING_LENGTH];
//     char column_data[MAX_ROWS][MAX_COLS][MAX_STRING_LENGTH];
//     int row = 0, col;

//     while (fgets(line, sizeof(line), csv_file)) {
//         col = 0;
//         char *token;
//         token = strtok(line, ",");
//         while (token != NULL) {
//             if (col < MAX_COLS) {
//                 strcpy(column_data[row][col], token);
//             }
//             token = strtok(NULL, ",");
//             col++;
//         }
//         row++;
//     }
//     fclose(csv_file);

//     // Print the data from each column
//     for (col = 0; col < MAX_COLS; col++) {
//         printf("Column %d:\n", col + 1);
//         for (row = 0; row < MAX_ROWS; row++) {
//             if (strlen(column_data[row][col]) > 0) {
//                 printf("%s\n", column_data[row][col]);
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }
