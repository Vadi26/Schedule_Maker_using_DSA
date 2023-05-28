#include <stdio.h>

int main() {
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Write headers
    fprintf(file, "Name, Age, City\n");

    // Write data rows
    fprintf(file, "John Doe, 25, New York\n");
    fprintf(file, "Jane Smith, 30, London\n");
    fprintf(file, "Bob Johnson, 35, Paris\n");

    fclose(file);
    printf("Data written to the file successfully.\n");

    return 0;
}
