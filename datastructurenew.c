// #include<stdio.h>
// #include<string.h>
// #include<stdlib.h>

// typedef struct node {
//     char *classroom_name;
//     char *weekday;
//     char *time;
//     char *faculty;
//     char *subject;
//     char *batch;
// }node;

// typedef struct ll_node {
//     node *schedule_node;
//     struct ll_node *prev, *next;
// }ll_node;

// ll_node *LL_array[5]; 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a single class
typedef struct {
    char classroom[50];
    char day[20];
    char time[20];
    char faculty[50];
    char subject[50];
    char class_name[50];
} Class;

// Structure to represent a node in the linked list
typedef struct Node {
    Class data;
    struct Node* next;
} Node;

// Array of linked lists to store the timetable
Node* timetable[5]; // Assuming 5 working days (Monday to Friday)

// Function to create a new node with given class data
Node* createNode(Class classInfo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = classInfo;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a class into the timetable
void insertClass(Class classInfo) {
    int dayIndex;
    
    if (strcmp(classInfo.day, "Monday") == 0)
        dayIndex = 0;
    else if (strcmp(classInfo.day, "Tuesday") == 0)
        dayIndex = 1;
    else if (strcmp(classInfo.day, "Wednesday") == 0)
        dayIndex = 2;
    else if (strcmp(classInfo.day, "Thursday") == 0)
        dayIndex = 3;
    else if (strcmp(classInfo.day, "Friday") == 0)
        dayIndex = 4;
    else {
        printf("Invalid day!\n");
        return;
    }
    
    Node* newNode = createNode(classInfo);
    
    if (timetable[dayIndex] == NULL) {
        timetable[dayIndex] = newNode;
    } else {
        Node* current = timetable[dayIndex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to display the timetable
void displayTimetable() {
    for (int i = 0; i < 5; i++) {
        printf("Day %d:\n", i + 1);
        if (timetable[i] == NULL) {
            printf("No classes scheduled\n");
        } else {
            Node* current = timetable[i];
            while (current != NULL) {
                printf("Classroom: %s\n", current->data.classroom);
                printf("Time: %s\n", current->data.time);
                printf("Faculty: %s\n", current->data.faculty);
                printf("Subject: %s\n", current->data.subject);
                printf("Class: %s\n", current->data.class_name);
                printf("\n");
                current = current->next;
            }
        }
    }
}

int main() {
    // Read data from CSV file and populate the timetable
    FILE* file = fopen("newdatabase.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Class classInfo;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", 
               classInfo.classroom, classInfo.day, classInfo.time,
               classInfo.faculty, classInfo.subject, classInfo.class_name);
        insertClass(classInfo);
    }
    
    fclose(file);
    
    // Display the timetable
    displayTimetable();

    return 0;
}