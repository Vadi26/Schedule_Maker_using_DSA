#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "header_for_edit.h"

//Functions for students 

void displayDayTimetable_for_student(char *class_name,char *weekday) {
    printf("Enter you classname among the following:\n1)SY_CE1\n2)SY_CE2\n3)TY_CE1\n4)TY_CE2\n5)BTCE1\n6)BTCE2\nFY_MT");
    scanf("%s",class_name);
    printf("Which day's schedule you wich to see:   ");
    scanf("%s",weekday);
    switch(weekday){
        case 'Monday':
            i=0;
            break;
        case 'Tuesday':
            i=1;
            break;
        case 'Wednesday':
            i=2;
            break;
        case 'Thursday':
            i=3;
            break;
        case 'Friday':
            i=4;
            break;
        default :
            printf("Please enter a valid working day!");
    }
    ll_Node *temp = timetable[i];
        if (timetable[i] == NULL) printf("No Schedule");
        else {
            while (temp != NULL) {
                if (!strcmp(temp->data.class_name, class_name)) printf("%s : \n Time : %s \n Subject : %s Faculty : %s \n \n Classroom : %s \n", temp->data.day, temp->data.time, temp->data.subject, temp->data.faculty, temp->data.classroom);
                temp = temp->next;
            }
        }
}