#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"

// \brief Function to schedule a new or extra leture
void Schedule_new_lecture(char *faculty_name, char *class_name) {
    int i;
    char weekday[20], classroom[20];
    printf("Enter the day on which you want to schedule a lecture : ");
    scanf("%s", weekday);
    printf("Students of %s are free in the following time slots : ", class_name);
    display_free_slots_for_class(weekday, class_name);

    printf("Do you have any preference for the classroom? (1-yes, 0-no) : ");
    scanf("%d", &i);
    if (i) {
        printf("Which classroom do you prefer? : ");
    }
}

void display_free_classrooms_at_given_time(char *weekday, char *time_slot) {
    int dayIndex = 0, free_time_for_classroom[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int i;
    if (strcmp(weekday, "Monday") == 0)
        dayIndex = 0;
    else if (strcmp(weekday, "Tuesday") == 0)
        dayIndex = 1;
    else if (strcmp(weekday, "Wednesday") == 0)
        dayIndex = 2;
    else if (strcmp(weekday, "Thursday") == 0)
        dayIndex = 3;
    else if (strcmp(weekday, "Friday") == 0)
        dayIndex = 4;

    ll_Node *temp = timetable[dayIndex];
    while (temp != NULL) {
        if (!strcmp(time_slot, temp->data.time)) printf("Classroom %s is not free. \n", temp->data.classroom);
        temp = temp->next;
    }
}

// \brief Utility function which returns 1 if the provided string is present in array
int does_string_exist_in_array(char *token) {
    if (CLASS_ROOMS[0] == NULL) return -1;
    for (int i = 0; i < 8; i++) {
        if(!strcmp(CLASS_ROOMS[i], token)) return 1;
    }
    return 0;
}

void fill_classrooms_in_array() {
    FILE *file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return; 
    }

    char line[100];
    char *token;
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        if (token != NULL) {
            CLASS_ROOMS[i] = token;
        }
        i++;
    }
    // for(i = )
    fclose(file);
}

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

    
    return 0;
}