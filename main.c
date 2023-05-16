// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// #define MAX_LENGTH 100
// #define MAX_FIELDS 5
// #define MAX_RECORDS 100

// int main() {
//     FILE *file;
//     char filename[] = "database.csv"; // Replace with your CSV file name

//     // Open the CSV file
//     file = fopen(filename, "r");
//     if (file == NULL) {
//         printf("Failed to open the file.\n");
//         return 1;
//     }

//     // Read and extract data from the CSV file
//     char line[MAX_LENGTH];
//     char *fields[MAX_FIELDS];
//     int recordCount = 0;

//     while (fgets(line, sizeof(line), file) != NULL) {
//         // Remove the trailing newline character
//         line[strcspn(line, "\n")] = '\0';

//         // Tokenize the line using comma as the delimiter
//         char *token = strtok(line, ",");
//         int fieldCount = 0;

//         while (token != NULL && fieldCount < MAX_FIELDS) {
//             // Allocate memory for each field and copy the token
//             fields[fieldCount] = malloc(strlen(token) + 1);
//             strcpy(fields[fieldCount], token);

//             token = strtok(NULL, ",");
//             fieldCount++;
//         }

//         // Process the extracted fields (e.g., print them)
//         for (int i = 0; i < fieldCount; i++) {
//             printf("%s\t", fields[i]);
//         }
//         printf("\n");

//         // Free memory allocated for fields
//         for (int i = 0; i < fieldCount; i++) {
//             free(fields[i]);
//         }

//         recordCount++;
//     }

//     // Close the file
//     fclose(file);

//     printf("Total records: %d\n", recordCount);

//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100
#define MAX_FIELDS 5
#define MAX_RECORDS 100

typedef struct {
    char field[MAX_LENGTH];
} Record;

typedef struct {
    Record fields[MAX_FIELDS];
    int fieldCount;
} Row;

typedef struct {
    Row rows[MAX_RECORDS];
    int rowCount;
} Table;

int main() {
    FILE *file;
    char filename[] = "database.csv"; // Replace with your CSV file name

    // Open the CSV file
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Create a table to store the extracted data
    Table table;
    table.rowCount = 0;

    // Read and extract data from the CSV file
    char line[MAX_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        // Remove the trailing newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize the line using comma as the delimiter
        char *token = strtok(line, ",");
        int fieldCount = 0;

        while (token != NULL && fieldCount < MAX_FIELDS) {
            // Copy the token into the corresponding field of the current row
            strcpy(table.rows[table.rowCount].fields[fieldCount].field, token);

            token = strtok(NULL, ",");
            fieldCount++;
        }

        // Set the fieldCount of the current row
        table.rows[table.rowCount].fieldCount = fieldCount;

        // Increment the rowCount of the table
        table.rowCount++;
    }

    // Close the file
    fclose(file);

    // Print the extracted data
    for (int i = 0; i < table.rowCount; i++) {
        Row row = table.rows[i];
        for (int j = 0; j < row.fieldCount; j++) {
            printf("%s\t", row.fields[j].field);
        }
        printf("\n");
    }

    printf("Total records: %d\n", table.rowCount);

    return 0;
}
