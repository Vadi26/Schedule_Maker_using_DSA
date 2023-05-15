#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELD_SIZE 50
#define CSV_FILE_PATH "schedule.csv"

typedef struct ScheduleNode {
    char day[MAX_FIELD_SIZE];
    char subject[MAX_FIELD_SIZE];
    char timeSlot[MAX_FIELD_SIZE];
    char classroom[MAX_FIELD_SIZE];
    char teacherName[MAX_FIELD_SIZE];
    struct ScheduleNode* next;
} ScheduleNode;

typedef struct {
    ScheduleNode* head;
} ScheduleList;

ScheduleNode* createScheduleNode(const char* day, const char* subject, const char* timeSlot, const char* classroom, const char* teacherName) {
    ScheduleNode* node = (ScheduleNode*)malloc(sizeof(ScheduleNode));
    if (node != NULL) {
        strcpy(node->day, day);
        strcpy(node->subject, subject);
        strcpy(node->timeSlot, timeSlot);
        strcpy(node->classroom, classroom);
        strcpy(node->teacherName, teacherName);
        node->next = NULL;
    }
    return node;
}

void destroyScheduleNode(ScheduleNode* node) {
    if (node != NULL) {
        free(node);
    }
}

void initializeScheduleList(ScheduleList* list) {
    list->head = NULL;
}

void destroyScheduleList(ScheduleList* list) {
    ScheduleNode* current = list->head;
    while (current != NULL) {
        ScheduleNode* next = current->next;
        destroyScheduleNode(current);
        current = next;
    }
}

void addSchedule(ScheduleList* list, const char* day, const char* subject, const char* timeSlot, const char* classroom, const char* teacherName) {
    ScheduleNode* node = createScheduleNode(day, subject, timeSlot, classroom, teacherName);
    if (node != NULL) {
        if (list->head == NULL) {
            list->head = node;
        } else {
            ScheduleNode* current = list->head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = node;
        }
    }
}

void printTeacherSchedule(const ScheduleList* list, const char* teacherName) {
    int found = 0;
    ScheduleNode* current = list->head;

    printf("Teacher Schedule for %s:\n", teacherName);
    while (current != NULL) {
        if (strcmp(current->teacherName, teacherName) == 0) {
            printf("Day: %s\n", current->day);
            printf("Subject: %s\n", current->subject);
            printf("Time Slot: %s\n", current->timeSlot);
            printf("Classroom: %s\n", current->classroom);
            printf("-----------------------\n");
            found = 1;
        }
        current = current->next;
    }
    
    if (!found) {
        printf("No schedule found for %s\n", teacherName);
    }
}

int main() {
    FILE* file = fopen(CSV_FILE_PATH, "r");
    if (file == NULL) {
        printf("Error opening the CSV file.\n");
        return 1;
    }
    
    ScheduleList scheduleList;
    initializeScheduleList(&scheduleList);
    
    char line[MAX_FIELD_SIZE * 6];  // Increased size to accommodate extra comma in the last field
    char* token;
    
    // Read schedules from the CSV file
    fgets(line, sizeof(line), file);  // Skip the header line
    while (fgets(line, sizeof(line), file) != NULL) {
        token = strtok(line, ",");
        char day[MAX_FIELD_SIZE];
        char subject[MAX_FIELD_SIZE];
        char timeSlot[MAX_FIELD_SIZE];
        char classroom[MAX_FIELD_SIZE];
        char teacherName[MAX_FIELD_SIZE];
        
        if (token != NULL) {
            strcpy(day, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(subject, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(timeSlot, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(classroom, token);
            token = strtok(NULL, ",");
        }
        if (token != NULL) {
            strcpy(teacherName, token);
        }
        
        addSchedule(&scheduleList, day, subject, timeSlot, classroom, teacherName);
    }
    
    // Print schedule for each teacher
    printTeacherSchedule(&scheduleList, "Aman Jhinga");
    printTeacherSchedule(&scheduleList, "Vinod Pachghare");
    printTeacherSchedule(&scheduleList, "Deepak Kshirsagar");
    printTeacherSchedule(&scheduleList, "Rahul B. Adhav");
    printTeacherSchedule(&scheduleList, "Siddharth Gaikwad");
    printTeacherSchedule(&scheduleList, "Soma Ghosh");
    printTeacherSchedule(&scheduleList, "Apte Sir");
    printTeacherSchedule(&scheduleList, "ECT Faculty");
    
    // Clean up resources
    destroyScheduleList(&scheduleList);
    fclose(file);
    
    return 0;
}
