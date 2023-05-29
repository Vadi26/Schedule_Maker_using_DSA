#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"

void displayDayTimetable_for_student(){
    char class_name[20];char weekday[20];
    printf("Enter you classname among the following:\n1)SY_CE1\n2)SY_CE2\n3)TY_CE1\n4)TY_CE2\n5)BT_CE1\n6)BT_CE2\n7)FY_MT\n");
    scanf("%s",class_name);
    printf("Which day's schedule you wish to see:   ");
    scanf("%s",weekday);
    int i = 0;
    while(i<5){
        ll_Node* temp = timetable[i];
        if(!strcmp(weekday,temp->data.day)) 
            break;
        i++;
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


int main() {
    // Read data from CSV file and populate the timetable
    FILE* file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }
    
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        Class classData;
        sscanf(line, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", 
               classData.classroom, classData.day, classData.time,
               classData.faculty, classData.subject, classData.class_name);
        insertClass(classData);
    }
    
    fclose(file);
    
    // Display the timetable
    //displayTimetable();
    displayDayTimetable_for_student();
    return 0;
}
