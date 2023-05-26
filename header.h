#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct time_slot_node {
    char *timing;
    char *faculty;
    char *subject;
    char *division;
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

// Created the array of classrooms
CN* classrooms[8];

CN *allocate_memory_for_classroom(char *classroom_name) {
    CN *classrooms = NULL;
    classrooms = (CN*)malloc(sizeof(CN));
    classrooms->classroom_name = classroom_name;
    classrooms->MON=(day_node*)malloc(sizeof(day_node));
    classrooms->MON->weekday="MONDAY";
    classrooms->MON->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->MON->TIME->next=classrooms->MON->TIME->prev=NULL;
    classrooms->MON->TIME->timing = NULL;

    classrooms->TUE=(day_node*)malloc(sizeof(day_node));
    classrooms->TUE->weekday="TUESDAY";
    classrooms->TUE->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->TUE->TIME->next=classrooms->TUE->TIME->prev=NULL;
    classrooms->TUE->TIME->timing = NULL;

    classrooms->WED=(day_node*)malloc(sizeof(day_node));
    classrooms->WED->weekday="WEDNESDAY";
    classrooms->WED->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->WED->TIME->next=classrooms->WED->TIME->prev=NULL;
    classrooms->WED->TIME->timing = NULL;
    
    classrooms->THU=(day_node*)malloc(sizeof(day_node));
    classrooms->THU->weekday="THURSDAY";
    classrooms->THU->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->THU->TIME->next=classrooms->THU->TIME->prev=NULL;
    classrooms->THU->TIME->timing = NULL;

    classrooms->FRI=(day_node*)malloc(sizeof(day_node));
    classrooms->FRI->weekday="FRIDAY";
    classrooms->FRI->TIME = (time_slot_node *)malloc(sizeof(time_slot_node));
    classrooms->FRI->TIME->next=classrooms->FRI->TIME->prev=NULL;
    classrooms->FRI->TIME->timing = NULL;

    return classrooms;
}

time_slot_node *create_New_time_slot_node (char *time, char *faculty, char *subject, char *batch) {
    time_slot_node *newNode = (time_slot_node *)malloc(sizeof(time_slot_node));
    newNode->timing = time;
    newNode->faculty = faculty;
    newNode->subject = subject;
    newNode->division = batch;
    newNode->next = NULL;

    return newNode;
}