#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct time_slot_node {
    char *timing;
    char *faculty;
    char *subject;
    char *class;
    struct time_slot_node *next, *prev;
}time_slot_node;

typedef struct day_node {
    char *weekday;
    time_slot_node *TIME;
}day_node;

typedef struct classroom_node {
    char *classroom_name;
    day_node *MON;
    day_node *TUE;
    day_node *WED;
    day_node *THU;
    day_node *FRI;
}CN;

int main() {
    // Created the array of classrooms
    CN* AC_101 = (CN*)malloc(sizeof(CN));
    AC_101->classroom_name = "AC-101";
    CN* AC_102 = (CN*)malloc(sizeof(CN));
    AC_102->classroom_name = "AC-102";
    FILE *csv_file = fopen("database.csv", "r");
    if (csv_file == NULL) {
        perror("Unable to open the file :(");
        exit(1);
    }

    char line[1024];
    int column = 0, row = 0;

    while(fgets(line, sizeof(line), csv_file)) {
        column = 0;
        row++;
        if(row == 1) continue;
        char *token;
        token = strtok(line, ",");
        while(token) {
            if (column == 0) {
                // Insert the classroom into classroom array
            }
 
            // Column 2
            if (column == 1) {
                // Connect the classroom element with weekday
            }
 
            // Column 3
            if (column == 2) {
                // Connect the weekday with linked list of time slots
            }
 
            // Column 4
            if (column == 3) {
                // Add faculty in the node which time slot will point to
            }

            // Column 5
            if (column == 4) {
                // Add subject ...
            }

            // Column 6
            if (column == 5) {
                // Add class/division
            }

            // printf("%s", token);
            token = strtok(NULL, ", ");
            column++;
        }
    }
}