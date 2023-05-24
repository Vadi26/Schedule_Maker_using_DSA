#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct time_slot_node {
    char *timing;
    char *faculty;
    char *subject;
    char *class;
    struct time_slot_node *next, *prev;
}time_slot_node;

typedef struct day_node {
    char *weekday;
    time_slot_node *TIME;
}day_node;

typedef struct classroom_node {
    char *classroom_name;
    day_node *MON;
    day_node *TUE;
    day_node *WED;
    day_node *THU;
    day_node *FRI;
}CN;

CN *allocate_memory_for_classroom(char *classroom_name) {
    CN *classrooms = NULL;
    classrooms = (CN*)malloc(sizeof(CN));
    classrooms->classroom_name = "AC-101";
    classrooms->MON=(day_node*)malloc(sizeof(day_node));
    classrooms->MON->weekday="MONDAY";
    classrooms->MON->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->MON->TIME->next=classrooms->MON->TIME->prev=NULL;

    classrooms->TUE=(day_node*)malloc(sizeof(day_node));
    classrooms->TUE->weekday="TUESDAY";
    classrooms->TUE->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->TUE->TIME->next=classrooms->TUE->TIME->prev=NULL;

    classrooms->WED=(day_node*)malloc(sizeof(day_node));
    classrooms->WED->weekday="WEDNESDAY";
    classrooms->WED->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->WED->TIME->next=classrooms->WED->TIME->prev=NULL;
    
    classrooms->THU=(day_node*)malloc(sizeof(day_node));
    classrooms->THU->weekday="THURSDAY";
    classrooms->THU->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->THU->TIME->next=classrooms->THU->TIME->prev=NULL;

    classrooms->FRI=(day_node*)malloc(sizeof(day_node));
    classrooms->FRI->weekday="FRIDAY";
    classrooms->FRI->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->FRI->TIME->next=classrooms->FRI->TIME->prev=NULL;

    return classrooms;
}

int main() {
    // Created the array of classrooms
    CN* classrooms[8];
    classrooms[0] = allocate_memory_for_classroom("AC-101");
    classrooms[1] = allocate_memory_for_classroom("AC-102");
    classrooms[2] = allocate_memory_for_classroom("AC-103");
    classrooms[3] = allocate_memory_for_classroom("AC-104");
    classrooms[4] = allocate_memory_for_classroom("AC-201");
    classrooms[5] = allocate_memory_for_classroom("AC-202");
    classrooms[6] = allocate_memory_for_classroom("AC-203");
    classrooms[7] = allocate_memory_for_classroom("AC-204");
    // Allocate memory and initialize each classroom
    classrooms[0] = (CN*)malloc(sizeof(CN));
    classrooms[0]->classroom_name = "AC-101";
    classrooms[0]->MON=(day_node*)malloc(sizeof(day_node));
    classrooms[0]->MON->weekday="MONDAY";
    classrooms[0]->MON->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms[0]->MON->TIME->next=classrooms[0]->MON->TIME->prev=NULL;

    classrooms[0]->TUE=(day_node*)malloc(sizeof(day_node));
    classrooms[0]->TUE->weekday="TUESDAY";
    classrooms[0]->TUE->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms[0]->TUE->TIME->next=classrooms[0]->TUE->TIME->prev=NULL;

    classrooms[0]->WED=(day_node*)malloc(sizeof(day_node));
    classrooms[0]->WED->weekday="WEDNESDAY";
    classrooms[0]->WED->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms[0]->WED->TIME->next=classrooms[0]->WED->TIME->prev=NULL;
    
    classrooms[0]->THU=(day_node*)malloc(sizeof(day_node));
    classrooms[0]->THU->weekday="THURSDAY";
    classrooms[0]->THU->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms[0]->THU->TIME->next=classrooms[0]->THU->TIME->prev=NULL;

    classrooms[0]->FRI=(day_node*)malloc(sizeof(day_node));
    classrooms[0]->FRI->weekday="FRIDAY";
    classrooms[0]->FRI->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms[0]->FRI->TIME->next=classrooms[0]->FRI->TIME->prev=NULL;

    classrooms[1] = (CN*)malloc(sizeof(CN));
    classrooms[1]->classroom_name = "AC-102";
    
    classrooms[2] = (CN*)malloc(sizeof(CN));
    classrooms[2]->classroom_name = "AC-103";
    
    classrooms[3] = (CN*)malloc(sizeof(CN));
    classrooms[3]->classroom_name = "AC-104";
    
    classrooms[4] = (CN*)malloc(sizeof(CN));
    classrooms[4]->classroom_name = "AC-201";
    
    classrooms[5] = (CN*)malloc(sizeof(CN));
    classrooms[5]->classroom_name = "AC-202";
    
    classrooms[6] = (CN*)malloc(sizeof(CN));
    classrooms[6]->classroom_name = "AC-203";
    
    classrooms[7] = (CN*)malloc(sizeof(CN));
    classrooms[7]->classroom_name = "AC-204";
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
                classrooms[0]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[0]->TUE->TIME->timing=time;
                classrooms[0]->TUE->TIME->faculty=faculty;
                classrooms[0]->TUE->TIME->subject=subject;
                classrooms[0]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[0]->WED->TIME->timing=time;
                classrooms[0]->WED->TIME->faculty=faculty;
                classrooms[0]->WED->TIME->subject=subject;
                classrooms[0]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[0]->THU->TIME->timing=time;
                classrooms[0]->THU->TIME->faculty=faculty;
                classrooms[0]->THU->TIME->subject=subject;
                classrooms[0]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[0]->FRI->TIME->timing=time;
                classrooms[0]->FRI->TIME->faculty=faculty;
                classrooms[0]->FRI->TIME->subject=subject;
                classrooms[0]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-102")
        {
            if (day=="Monday")
            {
                classrooms[1]->MON->TIME->timing=time;
                classrooms[1]->MON->TIME->faculty=faculty;
                classrooms[1]->MON->TIME->subject=subject;
                classrooms[1]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[1]->TUE->TIME->timing=time;
                classrooms[1]->TUE->TIME->faculty=faculty;
                classrooms[1]->TUE->TIME->subject=subject;
                classrooms[1]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[1]->WED->TIME->timing=time;
                classrooms[1]->WED->TIME->faculty=faculty;
                classrooms[1]->WED->TIME->subject=subject;
                classrooms[1]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[1]->THU->TIME->timing=time;
                classrooms[1]->THU->TIME->faculty=faculty;
                classrooms[1]->THU->TIME->subject=subject;
                classrooms[1]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[1]->FRI->TIME->timing=time;
                classrooms[1]->FRI->TIME->faculty=faculty;
                classrooms[1]->FRI->TIME->subject=subject;
                classrooms[1]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-103")
        {
            if (day=="Monday")
            {
                classrooms[2]->MON->TIME->timing=time;
                classrooms[2]->MON->TIME->faculty=faculty;
                classrooms[2]->MON->TIME->subject=subject;
                classrooms[2]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[2]->TUE->TIME->timing=time;
                classrooms[2]->TUE->TIME->faculty=faculty;
                classrooms[2]->TUE->TIME->subject=subject;
                classrooms[2]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[2]->WED->TIME->timing=time;
                classrooms[2]->WED->TIME->faculty=faculty;
                classrooms[2]->WED->TIME->subject=subject;
                classrooms[2]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[2]->THU->TIME->timing=time;
                classrooms[2]->THU->TIME->faculty=faculty;
                classrooms[2]->THU->TIME->subject=subject;
                classrooms[2]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[2]->FRI->TIME->timing=time;
                classrooms[2]->FRI->TIME->faculty=faculty;
                classrooms[2]->FRI->TIME->subject=subject;
                classrooms[2]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-104")
        {
            if (day=="Monday")
            {
                classrooms[3]->MON->TIME->timing=time;
                classrooms[3]->MON->TIME->faculty=faculty;
                classrooms[3]->MON->TIME->subject=subject;
                classrooms[3]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[3]->TUE->TIME->timing=time;
                classrooms[3]->TUE->TIME->faculty=faculty;
                classrooms[3]->TUE->TIME->subject=subject;
                classrooms[3]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[3]->WED->TIME->timing=time;
                classrooms[3]->WED->TIME->faculty=faculty;
                classrooms[3]->WED->TIME->subject=subject;
                classrooms[3]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[3]->THU->TIME->timing=time;
                classrooms[3]->THU->TIME->faculty=faculty;
                classrooms[3]->THU->TIME->subject=subject;
                classrooms[3]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[3]->FRI->TIME->timing=time;
                classrooms[3]->FRI->TIME->faculty=faculty;
                classrooms[3]->FRI->TIME->subject=subject;
                classrooms[3]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-201")
        {
            if (day=="Monday")
            {
                classrooms[4]->MON->TIME->timing=time;
                classrooms[4]->MON->TIME->faculty=faculty;
                classrooms[4]->MON->TIME->subject=subject;
                classrooms[4]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[4]->TUE->TIME->timing=time;
                classrooms[4]->TUE->TIME->faculty=faculty;
                classrooms[4]->TUE->TIME->subject=subject;
                classrooms[4]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[4]->WED->TIME->timing=time;
                classrooms[4]->WED->TIME->faculty=faculty;
                classrooms[4]->WED->TIME->subject=subject;
                classrooms[4]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[4]->THU->TIME->timing=time;
                classrooms[4]->THU->TIME->faculty=faculty;
                classrooms[4]->THU->TIME->subject=subject;
                classrooms[4]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[4]->FRI->TIME->timing=time;
                classrooms[4]->FRI->TIME->faculty=faculty;
                classrooms[4]->FRI->TIME->subject=subject;
                classrooms[4]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-202")
        {
            if (day=="Monday")
            {
                classrooms[5]->MON->TIME->timing=time;
                classrooms[5]->MON->TIME->faculty=faculty;
                classrooms[5]->MON->TIME->subject=subject;
                classrooms[5]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[5]->TUE->TIME->timing=time;
                classrooms[5]->TUE->TIME->faculty=faculty;
                classrooms[5]->TUE->TIME->subject=subject;
                classrooms[5]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[5]->WED->TIME->timing=time;
                classrooms[5]->WED->TIME->faculty=faculty;
                classrooms[5]->WED->TIME->subject=subject;
                classrooms[5]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[5]->THU->TIME->timing=time;
                classrooms[5]->THU->TIME->faculty=faculty;
                classrooms[5]->THU->TIME->subject=subject;
                classrooms[5]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[5]->FRI->TIME->timing=time;
                classrooms[5]->FRI->TIME->faculty=faculty;
                classrooms[5]->FRI->TIME->subject=subject;
                classrooms[5]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-203")
        {
            if (day=="Monday")
            {
                classrooms[6]->MON->TIME->timing=time;
                classrooms[6]->MON->TIME->faculty=faculty;
                classrooms[6]->MON->TIME->subject=subject;
                classrooms[6]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[6]->TUE->TIME->timing=time;
                classrooms[6]->TUE->TIME->faculty=faculty;
                classrooms[6]->TUE->TIME->subject=subject;
                classrooms[6]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[6]->WED->TIME->timing=time;
                classrooms[6]->WED->TIME->faculty=faculty;
                classrooms[6]->WED->TIME->subject=subject;
                classrooms[6]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[6]->THU->TIME->timing=time;
                classrooms[6]->THU->TIME->faculty=faculty;
                classrooms[6]->THU->TIME->subject=subject;
                classrooms[6]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[6]->FRI->TIME->timing=time;
                classrooms[6]->FRI->TIME->faculty=faculty;
                classrooms[6]->FRI->TIME->subject=subject;
                classrooms[6]->FRI->TIME->class=batch;
            }
        }
        else if (class=="AC-204")
        {
            if (day=="Monday")
            {
                classrooms[7]->MON->TIME->timing=time;
                classrooms[7]->MON->TIME->faculty=faculty;
                classrooms[7]->MON->TIME->subject=subject;
                classrooms[7]->MON->TIME->class=batch;
            }
            else if (day=="Tuesday")
            {
                classrooms[7]->TUE->TIME->timing=time;
                classrooms[7]->TUE->TIME->faculty=faculty;
                classrooms[7]->TUE->TIME->subject=subject;
                classrooms[7]->TUE->TIME->class=batch;
            }
            else if (day=="Wednesday")
            {
                classrooms[7]->WED->TIME->timing=time;
                classrooms[7]->WED->TIME->faculty=faculty;
                classrooms[7]->WED->TIME->subject=subject;
                classrooms[7]->WED->TIME->class=batch;
            }
            else if (day=="Thursday")
            {
                classrooms[7]->THU->TIME->timing=time;
                classrooms[7]->THU->TIME->faculty=faculty;
                classrooms[7]->THU->TIME->subject=subject;
                classrooms[7]->THU->TIME->class=batch;
            }
            else if (day=="Friday")
            {
                classrooms[7]->FRI->TIME->timing=time;
                classrooms[7]->FRI->TIME->faculty=faculty;
                classrooms[7]->FRI->TIME->subject=subject;
                classrooms[7]->FRI->TIME->class=batch;
            }
        }
        }
    }