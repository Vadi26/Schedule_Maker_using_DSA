#include <stdio.h>
#include <stdlib.h>
#include "header.h"
// #include "header_for_edit.h"

//Functions for students 

void displayDayTimetable_for_student(){
    char *class_name;char *weekday;
    printf("Enter you classname among the following:\n1)SY_CE1\n2)SY_CE2\n3)TY_CE1\n4)TY_CE2\n5)BTCE1\n6)BTCE2\nFY_MT");
    scanf("%s",class_name);
    printf("Which day's schedule you wich to see:   ");
    scanf("%s",weekday);
    int dayIndex;
    
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
    int i = 0;
    while(i<5){
        ll_Node* temp = timetable[dayIndex];
        if (timetable[dayIndex] == NULL) printf("No Schedule");
        else {
            while (temp != NULL) {
                if (!strcmp(temp->data.class_name, class_name)) printf("\n Time : %s \n Subject : %s Faculty : %s \n \n Classroom : %s \n", temp->data.time, temp->data.subject, temp->data.faculty, temp->data.classroom);
                temp = temp->next;
            }
        }
    }
}