#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

void display_Monday_schedule() {
    time_slot_node *temp = NULL;
    for (int i = 0; i < 7; i++) {
        temp = classrooms[i]->MON->TIME;
        printf("%s %s %s %s %s %s \n", classrooms[i]->classroom_name, classrooms[i]->MON->weekday, classrooms[i]->MON->TIME->timing, classrooms[i]->MON->TIME->faculty, classrooms[i]->MON->TIME->subject, classrooms[i]->MON->TIME->division);
        while (temp != NULL) {
            printf("\t %s %s %s %s \n", temp->timing, temp->faculty, temp->subject, temp->division);
            temp = temp->next;
        }
    }

}

int main() {
    // Allocate memory and initialize each classroom
    classrooms[0] = allocate_memory_for_classroom("AC-101");
    classrooms[1] = allocate_memory_for_classroom("AC-102");
    classrooms[2] = allocate_memory_for_classroom("AC-103");
    classrooms[3] = allocate_memory_for_classroom("AC-104");
    classrooms[4] = allocate_memory_for_classroom("AC-201");
    classrooms[5] = allocate_memory_for_classroom("AC-202");
    classrooms[6] = allocate_memory_for_classroom("AC-203");
    classrooms[7] = allocate_memory_for_classroom("AC-204");

    FILE *csv_file = fopen("database.csv", "r");
    if (csv_file == NULL) {
        perror("Unable to open the file :(");
        exit(1);
    }

    char line[1024];
    int column = 0, row = 0;
    char *class, *batch, *faculty, *time, *day, *subject;

    while(fgets(line, sizeof(line), csv_file)) {
        column = 0;
        row++;
        // if (row == 1) continue;
        char *token;
        token = strtok(line, ",");
        while(token != NULL) {
            if (column == 0) {
                // if (token == "LUNCH") break;
                class = token;
            }

            // Column 2
            if (column == 1) {
                // Connect the classroom element with weekday
                day=token;
            }

            // Column 3
            if (column == 2) {
                // Connect the weekday with linked list of time slots
                time= token;
            }

            // Column 4
            if (column == 3) {
                // Add faculty in the node which time slot will point to
                faculty= token;
            }

            // Column 5
            if (column == 4) {
                // Add subject ...
                subject=token;
            }

            // Column 6
            if (column == 5) {
                // Add class/division
                batch=token;
            }

            // printf("%s", token);
            token = strtok(NULL, ", ");
            column++;
        }
        // if (!strcmp(token, "LUNCH")) continue;
        // else {
        if (!strcmp(class, "AC-101"))
        {   
            if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[0]->MON->TIME->timing == NULL) {
                    classrooms[0]->MON->TIME->timing=time;
                    classrooms[0]->MON->TIME->faculty=faculty;
                    classrooms[0]->MON->TIME->subject=subject;
                    classrooms[0]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[0]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[0]->TUE->TIME->timing == NULL) {
                    classrooms[0]->TUE->TIME->timing=time;
                    classrooms[0]->TUE->TIME->faculty=faculty;
                    classrooms[0]->TUE->TIME->subject=subject;
                    classrooms[0]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[0]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[0]->WED->TIME->timing == NULL) {
                    classrooms[0]->WED->TIME->timing=time;
                    classrooms[0]->WED->TIME->faculty=faculty;
                    classrooms[0]->WED->TIME->subject=subject;
                    classrooms[0]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[0]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[0]->THU->TIME->timing == NULL) {
                    classrooms[0]->THU->TIME->timing=time;
                    classrooms[0]->THU->TIME->faculty=faculty;
                    classrooms[0]->THU->TIME->subject=subject;
                    classrooms[0]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[0]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[0]->FRI->TIME->timing == NULL) {
                    classrooms[0]->FRI->TIME->timing=time;
                    classrooms[0]->FRI->TIME->faculty=faculty;
                    classrooms[0]->FRI->TIME->subject=subject;
                    classrooms[0]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[0]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-102"))
        {
            if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[1]->MON->TIME->timing == NULL) {
                    classrooms[1]->MON->TIME->timing=time;
                    classrooms[1]->MON->TIME->faculty=faculty;
                    classrooms[1]->MON->TIME->subject=subject;
                    classrooms[1]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[1]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[1]->TUE->TIME->timing == NULL) {
                    classrooms[1]->TUE->TIME->timing=time;
                    classrooms[1]->TUE->TIME->faculty=faculty;
                    classrooms[1]->TUE->TIME->subject=subject;
                    classrooms[1]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[1]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[1]->WED->TIME->timing == NULL) {
                    classrooms[1]->WED->TIME->timing=time;
                    classrooms[1]->WED->TIME->faculty=faculty;
                    classrooms[1]->WED->TIME->subject=subject;
                    classrooms[1]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[1]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[1]->THU->TIME->timing == NULL) {
                    classrooms[1]->THU->TIME->timing=time;
                    classrooms[1]->THU->TIME->faculty=faculty;
                    classrooms[1]->THU->TIME->subject=subject;
                    classrooms[1]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[1]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[1]->FRI->TIME->timing == NULL) {
                    classrooms[1]->FRI->TIME->timing=time;
                    classrooms[1]->FRI->TIME->faculty=faculty;
                    classrooms[1]->FRI->TIME->subject=subject;
                    classrooms[1]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[1]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-103"))
        {
        if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[2]->MON->TIME->timing == NULL) {
                    classrooms[2]->MON->TIME->timing=time;
                    classrooms[2]->MON->TIME->faculty=faculty;
                    classrooms[2]->MON->TIME->subject=subject;
                    classrooms[2]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[2]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[2]->TUE->TIME->timing == NULL) {
                    classrooms[2]->TUE->TIME->timing=time;
                    classrooms[2]->TUE->TIME->faculty=faculty;
                    classrooms[2]->TUE->TIME->subject=subject;
                    classrooms[2]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[2]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[2]->WED->TIME->timing == NULL) {
                    classrooms[2]->WED->TIME->timing=time;
                    classrooms[2]->WED->TIME->faculty=faculty;
                    classrooms[2]->WED->TIME->subject=subject;
                    classrooms[2]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[2]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[2]->THU->TIME->timing == NULL) {
                    classrooms[2]->THU->TIME->timing=time;
                    classrooms[2]->THU->TIME->faculty=faculty;
                    classrooms[2]->THU->TIME->subject=subject;
                    classrooms[2]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[2]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[2]->FRI->TIME->timing == NULL) {
                    classrooms[2]->FRI->TIME->timing=time;
                    classrooms[2]->FRI->TIME->faculty=faculty;
                    classrooms[2]->FRI->TIME->subject=subject;
                    classrooms[2]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[2]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-104"))
        {
            if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[3]->MON->TIME->timing == NULL) {
                    classrooms[3]->MON->TIME->timing=time;
                    classrooms[3]->MON->TIME->faculty=faculty;
                    classrooms[3]->MON->TIME->subject=subject;
                    classrooms[3]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[3]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[3]->TUE->TIME->timing == NULL) {
                    classrooms[3]->TUE->TIME->timing=time;
                    classrooms[3]->TUE->TIME->faculty=faculty;
                    classrooms[3]->TUE->TIME->subject=subject;
                    classrooms[3]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[3]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[3]->WED->TIME->timing == NULL) {
                    classrooms[3]->WED->TIME->timing=time;
                    classrooms[3]->WED->TIME->faculty=faculty;
                    classrooms[3]->WED->TIME->subject=subject;
                    classrooms[3]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[3]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[3]->THU->TIME->timing == NULL) {
                    classrooms[3]->THU->TIME->timing=time;
                    classrooms[3]->THU->TIME->faculty=faculty;
                    classrooms[3]->THU->TIME->subject=subject;
                    classrooms[3]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[3]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[3]->FRI->TIME->timing == NULL) {
                    classrooms[3]->FRI->TIME->timing=time;
                    classrooms[3]->FRI->TIME->faculty=faculty;
                    classrooms[3]->FRI->TIME->subject=subject;
                    classrooms[3]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[3]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-201"))
        {
           if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[4]->MON->TIME->timing == NULL) {
                    classrooms[4]->MON->TIME->timing=time;
                    classrooms[4]->MON->TIME->faculty=faculty;
                    classrooms[4]->MON->TIME->subject=subject;
                    classrooms[4]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[4]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[4]->TUE->TIME->timing == NULL) {
                    classrooms[4]->TUE->TIME->timing=time;
                    classrooms[4]->TUE->TIME->faculty=faculty;
                    classrooms[4]->TUE->TIME->subject=subject;
                    classrooms[4]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[4]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[4]->WED->TIME->timing == NULL) {
                    classrooms[4]->WED->TIME->timing=time;
                    classrooms[4]->WED->TIME->faculty=faculty;
                    classrooms[4]->WED->TIME->subject=subject;
                    classrooms[4]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[4]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[4]->THU->TIME->timing == NULL) {
                    classrooms[4]->THU->TIME->timing=time;
                    classrooms[4]->THU->TIME->faculty=faculty;
                    classrooms[4]->THU->TIME->subject=subject;
                    classrooms[4]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[4]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[4]->FRI->TIME->timing == NULL) {
                    classrooms[4]->FRI->TIME->timing=time;
                    classrooms[4]->FRI->TIME->faculty=faculty;
                    classrooms[4]->FRI->TIME->subject=subject;
                    classrooms[4]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[4]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-202"))
        {
            if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[5]->MON->TIME->timing == NULL) {
                    classrooms[5]->MON->TIME->timing=time;
                    classrooms[5]->MON->TIME->faculty=faculty;
                    classrooms[5]->MON->TIME->subject=subject;
                    classrooms[5]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[5]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[5]->TUE->TIME->timing == NULL) {
                    classrooms[5]->TUE->TIME->timing=time;
                    classrooms[5]->TUE->TIME->faculty=faculty;
                    classrooms[5]->TUE->TIME->subject=subject;
                    classrooms[5]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[5]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[5]->WED->TIME->timing == NULL) {
                    classrooms[5]->WED->TIME->timing=time;
                    classrooms[5]->WED->TIME->faculty=faculty;
                    classrooms[5]->WED->TIME->subject=subject;
                    classrooms[5]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[5]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[5]->THU->TIME->timing == NULL) {
                    classrooms[5]->THU->TIME->timing=time;
                    classrooms[5]->THU->TIME->faculty=faculty;
                    classrooms[5]->THU->TIME->subject=subject;
                    classrooms[5]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[5]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[5]->FRI->TIME->timing == NULL) {
                    classrooms[5]->FRI->TIME->timing=time;
                    classrooms[5]->FRI->TIME->faculty=faculty;
                    classrooms[5]->FRI->TIME->subject=subject;
                    classrooms[5]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[5]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-203"))
        {
            if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[6]->MON->TIME->timing == NULL) {
                    classrooms[6]->MON->TIME->timing=time;
                    classrooms[6]->MON->TIME->faculty=faculty;
                    classrooms[6]->MON->TIME->subject=subject;
                    classrooms[6]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[6]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[6]->TUE->TIME->timing == NULL) {
                    classrooms[6]->TUE->TIME->timing=time;
                    classrooms[6]->TUE->TIME->faculty=faculty;
                    classrooms[6]->TUE->TIME->subject=subject;
                    classrooms[6]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[6]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[6]->WED->TIME->timing == NULL) {
                    classrooms[6]->WED->TIME->timing=time;
                    classrooms[6]->WED->TIME->faculty=faculty;
                    classrooms[6]->WED->TIME->subject=subject;
                    classrooms[6]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[6]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[6]->THU->TIME->timing == NULL) {
                    classrooms[6]->THU->TIME->timing=time;
                    classrooms[6]->THU->TIME->faculty=faculty;
                    classrooms[6]->THU->TIME->subject=subject;
                    classrooms[6]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[6]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[6]->FRI->TIME->timing == NULL) {
                    classrooms[6]->FRI->TIME->timing=time;
                    classrooms[6]->FRI->TIME->faculty=faculty;
                    classrooms[6]->FRI->TIME->subject=subject;
                    classrooms[6]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[6]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        else if (!strcmp(class, "AC-204"))
        {
            if (!strcmp(day, "Monday"))
            {   
                // this is written to check if the linked list is empty or not and then operation is done accordingly
                if (classrooms[7]->MON->TIME->timing == NULL) {
                    classrooms[7]->MON->TIME->timing=time;
                    classrooms[7]->MON->TIME->faculty=faculty;
                    classrooms[7]->MON->TIME->subject=subject;
                    classrooms[7]->MON->TIME->division= batch;
                }
                else {
                    time_slot_node *temp = classrooms[7]->MON->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Tuesday"))
            {
                if (classrooms[7]->TUE->TIME->timing == NULL) {
                    classrooms[7]->TUE->TIME->timing=time;
                    classrooms[7]->TUE->TIME->faculty=faculty;
                    classrooms[7]->TUE->TIME->subject=subject;
                    classrooms[7]->TUE->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[7]->TUE->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Wednesday"))
            {
                if (classrooms[7]->WED->TIME->timing == NULL) {
                    classrooms[7]->WED->TIME->timing=time;
                    classrooms[7]->WED->TIME->faculty=faculty;
                    classrooms[7]->WED->TIME->subject=subject;
                    classrooms[7]->WED->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[7]->WED->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Thursday"))
            {   
                if (classrooms[7]->THU->TIME->timing == NULL) {
                    classrooms[7]->THU->TIME->timing=time;
                    classrooms[7]->THU->TIME->faculty=faculty;
                    classrooms[7]->THU->TIME->subject=subject;
                    classrooms[7]->THU->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[7]->THU->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
            else if (!strcmp(day, "Friday"))
            {   
                if (classrooms[7]->FRI->TIME->timing == NULL) {
                    classrooms[7]->FRI->TIME->timing=time;
                    classrooms[7]->FRI->TIME->faculty=faculty;
                    classrooms[7]->FRI->TIME->subject=subject;
                    classrooms[7]->FRI->TIME->division=batch;
                }
                else {
                    time_slot_node *temp = classrooms[7]->FRI->TIME;
                    while (temp->next != NULL) temp = temp->next;
                    temp->next = create_New_time_slot_node(time, faculty, subject, batch);
                }
            }
        }
        // }
    }
    display_Monday_schedule();

    return 0;
}