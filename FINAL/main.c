#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"header.h"

int main() {
    // Created the array of classrooms
    CN* classrooms[8];
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
    char* class, batch, faculty, time, day,subject;

    while(fgets(line, sizeof(line), csv_file)) {
        column = 0;
        row++;
        if(row == 1) continue;
        char *token;
        token = strtok(line, ",");
        while(token) {
            if (column == 0)
            class=token;

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
        if (class=="AC-101")
        {
            if (day=="Monday")
            {
                classrooms[0]->MON->TIME->timing=time;
                classrooms[0]->MON->TIME->faculty=faculty;
                classrooms[0]->MON->TIME->subject=subject;
                classrooms[0]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[0]->TUE->TIME->timing=time;
                classrooms[0]->TUE->TIME->faculty=faculty;
                classrooms[0]->TUE->TIME->subject=subject;
                classrooms[0]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[0]->WED->TIME->timing=time;
                classrooms[0]->WED->TIME->faculty=faculty;
                classrooms[0]->WED->TIME->subject=subject;
                classrooms[0]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[0]->THU->TIME->timing=time;
                classrooms[0]->THU->TIME->faculty=faculty;
                classrooms[0]->THU->TIME->subject=subject;
                classrooms[0]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[0]->FRI->TIME->timing=time;
                classrooms[0]->FRI->TIME->faculty=faculty;
                classrooms[0]->FRI->TIME->subject=subject;
                classrooms[0]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-102")
        {
            if (day=="Monday")
            {
                classrooms[1]->MON->TIME->timing=time;
                classrooms[1]->MON->TIME->faculty=faculty;
                classrooms[1]->MON->TIME->subject=subject;
                classrooms[1]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[1]->TUE->TIME->timing=time;
                classrooms[1]->TUE->TIME->faculty=faculty;
                classrooms[1]->TUE->TIME->subject=subject;
                classrooms[1]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[1]->WED->TIME->timing=time;
                classrooms[1]->WED->TIME->faculty=faculty;
                classrooms[1]->WED->TIME->subject=subject;
                classrooms[1]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[1]->THU->TIME->timing=time;
                classrooms[1]->THU->TIME->faculty=faculty;
                classrooms[1]->THU->TIME->subject=subject;
                classrooms[1]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[1]->FRI->TIME->timing=time;
                classrooms[1]->FRI->TIME->faculty=faculty;
                classrooms[1]->FRI->TIME->subject=subject;
                classrooms[1]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-103")
        {
            if (day=="Monday")
            {
                classrooms[2]->MON->TIME->timing=time;
                classrooms[2]->MON->TIME->faculty=faculty;
                classrooms[2]->MON->TIME->subject=subject;
                classrooms[2]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[2]->TUE->TIME->timing=time;
                classrooms[2]->TUE->TIME->faculty=faculty;
                classrooms[2]->TUE->TIME->subject=subject;
                classrooms[2]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[2]->WED->TIME->timing=time;
                classrooms[2]->WED->TIME->faculty=faculty;
                classrooms[2]->WED->TIME->subject=subject;
                classrooms[2]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[2]->THU->TIME->timing=time;
                classrooms[2]->THU->TIME->faculty=faculty;
                classrooms[2]->THU->TIME->subject=subject;
                classrooms[2]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[2]->FRI->TIME->timing=time;
                classrooms[2]->FRI->TIME->faculty=faculty;
                classrooms[2]->FRI->TIME->subject=subject;
                classrooms[2]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-104")
        {
            if (day=="Monday")
            {
                classrooms[3]->MON->TIME->timing=time;
                classrooms[3]->MON->TIME->faculty=faculty;
                classrooms[3]->MON->TIME->subject=subject;
                classrooms[3]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[3]->TUE->TIME->timing=time;
                classrooms[3]->TUE->TIME->faculty=faculty;
                classrooms[3]->TUE->TIME->subject=subject;
                classrooms[3]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[3]->WED->TIME->timing=time;
                classrooms[3]->WED->TIME->faculty=faculty;
                classrooms[3]->WED->TIME->subject=subject;
                classrooms[3]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[3]->THU->TIME->timing=time;
                classrooms[3]->THU->TIME->faculty=faculty;
                classrooms[3]->THU->TIME->subject=subject;
                classrooms[3]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[3]->FRI->TIME->timing=time;
                classrooms[3]->FRI->TIME->faculty=faculty;
                classrooms[3]->FRI->TIME->subject=subject;
                classrooms[3]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-201")
        {
            if (day=="Monday")
            {
                classrooms[4]->MON->TIME->timing=time;
                classrooms[4]->MON->TIME->faculty=faculty;
                classrooms[4]->MON->TIME->subject=subject;
                classrooms[4]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[4]->TUE->TIME->timing=time;
                classrooms[4]->TUE->TIME->faculty=faculty;
                classrooms[4]->TUE->TIME->subject=subject;
                classrooms[4]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[4]->WED->TIME->timing=time;
                classrooms[4]->WED->TIME->faculty=faculty;
                classrooms[4]->WED->TIME->subject=subject;
                classrooms[4]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[4]->THU->TIME->timing=time;
                classrooms[4]->THU->TIME->faculty=faculty;
                classrooms[4]->THU->TIME->subject=subject;
                classrooms[4]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[4]->FRI->TIME->timing=time;
                classrooms[4]->FRI->TIME->faculty=faculty;
                classrooms[4]->FRI->TIME->subject=subject;
                classrooms[4]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-202")
        {
            if (day=="Monday")
            {
                classrooms[5]->MON->TIME->timing=time;
                classrooms[5]->MON->TIME->faculty=faculty;
                classrooms[5]->MON->TIME->subject=subject;
                classrooms[5]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[5]->TUE->TIME->timing=time;
                classrooms[5]->TUE->TIME->faculty=faculty;
                classrooms[5]->TUE->TIME->subject=subject;
                classrooms[5]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[5]->WED->TIME->timing=time;
                classrooms[5]->WED->TIME->faculty=faculty;
                classrooms[5]->WED->TIME->subject=subject;
                classrooms[5]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[5]->THU->TIME->timing=time;
                classrooms[5]->THU->TIME->faculty=faculty;
                classrooms[5]->THU->TIME->subject=subject;
                classrooms[5]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[5]->FRI->TIME->timing=time;
                classrooms[5]->FRI->TIME->faculty=faculty;
                classrooms[5]->FRI->TIME->subject=subject;
                classrooms[5]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-203")
        {
            if (day=="Monday")
            {
                classrooms[6]->MON->TIME->timing=time;
                classrooms[6]->MON->TIME->faculty=faculty;
                classrooms[6]->MON->TIME->subject=subject;
                classrooms[6]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[6]->TUE->TIME->timing=time;
                classrooms[6]->TUE->TIME->faculty=faculty;
                classrooms[6]->TUE->TIME->subject=subject;
                classrooms[6]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[6]->WED->TIME->timing=time;
                classrooms[6]->WED->TIME->faculty=faculty;
                classrooms[6]->WED->TIME->subject=subject;
                classrooms[6]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[6]->THU->TIME->timing=time;
                classrooms[6]->THU->TIME->faculty=faculty;
                classrooms[6]->THU->TIME->subject=subject;
                classrooms[6]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[6]->FRI->TIME->timing=time;
                classrooms[6]->FRI->TIME->faculty=faculty;
                classrooms[6]->FRI->TIME->subject=subject;
                classrooms[6]->FRI->TIME->division=batch;
            }
        }
        else if (class=="AC-204")
        {
            if (day=="Monday")
            {
                classrooms[7]->MON->TIME->timing=time;
                classrooms[7]->MON->TIME->faculty=faculty;
                classrooms[7]->MON->TIME->subject=subject;
                classrooms[7]->MON->TIME->division=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[7]->TUE->TIME->timing=time;
                classrooms[7]->TUE->TIME->faculty=faculty;
                classrooms[7]->TUE->TIME->subject=subject;
                classrooms[7]->TUE->TIME->division=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[7]->WED->TIME->timing=time;
                classrooms[7]->WED->TIME->faculty=faculty;
                classrooms[7]->WED->TIME->subject=subject;
                classrooms[7]->WED->TIME->division=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[7]->THU->TIME->timing=time;
                classrooms[7]->THU->TIME->faculty=faculty;
                classrooms[7]->THU->TIME->subject=subject;
                classrooms[7]->THU->TIME->division=batch;
            }
            else if (day=="Friday")
            {
                classrooms[7]->FRI->TIME->timing=time;
                classrooms[7]->FRI->TIME->faculty=faculty;
                classrooms[7]->FRI->TIME->subject=subject;
                classrooms[7]->FRI->TIME->division=batch;
            }
        }
        }
}