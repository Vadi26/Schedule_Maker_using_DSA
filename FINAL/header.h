#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure to represent a single class
typedef struct {
    char classroom[50];
    char day[20];
    char time[20];
    char faculty[50];
    char subject[50];
    char class_name[50];
} Class;

// Structure to represent a ll_Node in the linked list
typedef struct ll_Node {
    Class data;
    struct ll_Node* next;
} ll_Node;

// Array of linked lists to store the timetable
ll_Node* timetable[5]; // Assuming 5 working days (Monday to Friday)

// Function to create a new ll_Node with given class data
ll_Node* createll_Node(Class classData) {
    ll_Node* newll_Node = (ll_Node*)malloc(sizeof(ll_Node));
    newll_Node->data = classData;
    newll_Node->next = NULL;
    return newll_Node;
}

// Function to insert a class into the timetable
void insertClass(Class classData) {
    int dayIndex;
    
    if (strcmp(classData.day, "Monday") == 0)
        dayIndex = 0;
    else if (strcmp(classData.day, "Tuesday") == 0)
        dayIndex = 1;
    else if (strcmp(classData.day, "Wednesday") == 0)
        dayIndex = 2;
    else if (strcmp(classData.day, "Thursday") == 0)
        dayIndex = 3;
    else if (strcmp(classData.day, "Friday") == 0)
        dayIndex = 4;
    else {
        printf("Invalid day!\n");
        return;
    }
    
    ll_Node* newll_Node = createll_Node(classData);
    
    if (timetable[dayIndex] == NULL) {
        timetable[dayIndex] = newll_Node;
    } else {
        ll_Node* current = timetable[dayIndex];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newll_Node;
    }
}

// Function to display the timetable
void displayTimetable() {
    for (int i = 0; i < 5; i++) {
        printf("Day %d:\n", i + 1);
        if (timetable[i] == NULL) {
            printf("No classes scheduled\n");
        } else {
            ll_Node* current = timetable[i];
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