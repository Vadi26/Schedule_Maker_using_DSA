#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"

int main() {
    // Read data from CSV file and populate the timetable
    FILE* file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Class classData;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", 
               classData.classroom, classData.day, classData.time,
               classData.faculty, classData.subject, classData.class_name);
        insertClass(classData);
    }
    
    fclose(file);

    display_free_slots_for_classroom("Monday", "AC-101");
    // display_free_slots_for_class("Monday", "SY_COMP2");
    // displayTimetable();
    // char class_name[30];
    // scanf("%s", class_name);
    // display_schedule_for_class(class_name);

    
    return 0;
}