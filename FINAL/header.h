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

// \brief This function will display timetable of the provided faculty
void display_schedule_for_faculty(char *faculty_name) {
    for(int i = 0; i < 5; i++) {
        ll_Node *temp = timetable[i];
        while (temp != NULL) {
            if (!strcmp(temp->data.faculty, faculty_name)) printf("%s : \n Time : %s \n Subject : %s \n Classroom : %s \n Batch : %s \n", temp->data.day, temp->data.time, temp->data.subject, temp->data.classroom, temp->data.class_name);
            temp = temp->next;
        }
    }
}

// \brief function to display timetable of a particular class
void display_schedule_for_class (char *class_name) {
    for(int i = 0; i < 5; i++) {
        ll_Node *temp = timetable[i];
        if (timetable[i] == NULL) printf("No Schedule");
        else {
            while (temp != NULL) {
                if (!strcmp(temp->data.class_name, class_name)) printf("%s : \n Time : %s \n Subject : %s Faculty : %s \n \n Classroom : %s \n", temp->data.day, temp->data.time, temp->data.subject, temp->data.faculty, temp->data.classroom);
                temp = temp->next;
            }
        }
    }
}

char *TIME_SLOTS[10] = {"08:00-09:00", "09:00-10:00", "10:00-11:00", "11:00-12:00", "12:00-13:00", "13:00-14:00", "14:00-15:00", "15:00-16:00", "16:00-17:00", "17:00-18:00"};

// \brief Function to display the free slots of a class on a given day
void display_free_slots_for_class(char *weekday, char *class_name) {
    int dayIndex = 0, time_slot_index[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
    int i;
    // time_slot_index will store the index of time slots that are NOT free
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
        if (!strcmp(temp->data.class_name, class_name)) {
            for (i = 0; i < 10; i++) {
                // if (!strcmp(temp->data.classroom, "LUNCH")) time_slot_index[i] = i;
                if (!strcmp(TIME_SLOTS[i], temp->data.time)) time_slot_index[i] = i;
            }
        }
        temp = temp->next;
    }
    printf("Free slots for the class %s are : \n", class_name);
    for (i = 0; i < 10; i++) {
        if (time_slot_index[i] == -1) printf("%s \n", TIME_SLOTS[i]);
    }
}

// \brief This function will change the integer array such that the indexes which have free slots will have a -1 at that position else it will have a different number
// Be sure to change the free_time_slot_index array back to its original contents after using the function once
int free_time_slot_index[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
void return_free_slots_for_class(char *weekday, char *class_name) {
    int dayIndex = 0;
    int i;
    // time_slot_index will store the index of time slots that are NOT free
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
        if (!strcmp(temp->data.class_name, class_name)) {
            for (i = 0; i < 10; i++) {
                // if (!strcmp(temp->data.classroom, "LUNCH")) time_slot_index[i] = i;
                if (!strcmp(TIME_SLOTS[i], temp->data.time)) free_time_slot_index[i] = i;
            }
        }
        temp = temp->next;
    }
}

int free_classroom_slot_index[10] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
void display_free_slots_for_classroom(char *weekday, char *classroom_name) {
    int dayIndex = 0;
    int i;
    // time_slot_index will store the index of time slots that are NOT free
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
        if (!strcmp(temp->data.classroom, classroom_name)) {
            for (i = 0; i < 10; i++) {
                // if (!strcmp(temp->data.classroom, "LUNCH")) time_slot_index[i] = i;
                if (!strcmp(TIME_SLOTS[i], temp->data.time)) free_classroom_slot_index[i] = i;
            }
        }
        temp = temp->next;
    }
    printf("Free slots for the classroom %s are : \n", classroom_name);
    for (i = 0; i < 10; i++) {
        if (free_classroom_slot_index[i] == -1) printf("%s \n", TIME_SLOTS[i]);
    }
}

// \brief This function will change the integer array such that the indexes which have free slots will have a -1 at that position else it will have a different number
// Be sure to change the free_classroom_slot_index array back to its original contents after using the function once
void return_free_slots_for_classroom(char *weekday, char *classroom_name) {
    int dayIndex = 0;
    int i;
    // time_slot_index will store the index of time slots that are NOT free
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
        if (!strcmp(temp->data.classroom, classroom_name)) {
            for (i = 0; i < 10; i++) {
                // if (!strcmp(temp->data.classroom, "LUNCH")) time_slot_index[i] = i;
                if (!strcmp(TIME_SLOTS[i], temp->data.time)) free_classroom_slot_index[i] = i;
            }
        }
        temp = temp->next;
    }
}

// \brief Function to cancel a lecture. Firstly it will check if the provided time slot had a lecture of that particular faculty or not. If the faculty did not have any lecture at that time then it will print cannot cancel lecture and exit
void cancel_lecture(char *faculty_name, char *time_slot);