// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include"header.h"

// void display_Monday_schedule() {
//     time_slot_node *temp = NULL;
//     for (int i = 0; i < 7; i++) {
//         temp = classrooms[i]->MON->TIME;
//         printf("%s %s %s %s %s %s \n", classrooms[i]->classroom_name, classrooms[i]->MON->weekday, classrooms[i]->MON->TIME->timing, classrooms[i]->MON->TIME->faculty, classrooms[i]->MON->TIME->subject, classrooms[i]->MON->TIME->division);
//         while (temp != NULL) {
//             printf("\t %s %s %s %s \n", temp->timing, temp->faculty, temp->subject, temp->division);
//             temp = temp->next;
//         }
//     }

// }

// int main() {
//     // Allocate memory and initialize each classroom
//     classrooms[0] = allocate_memory_for_classroom("AC-101");
//     classrooms[1] = allocate_memory_for_classroom("AC-102");
//     classrooms[2] = allocate_memory_for_classroom("AC-103");
//     classrooms[3] = allocate_memory_for_classroom("AC-104");
//     classrooms[4] = allocate_memory_for_classroom("AC-201");
//     classrooms[5] = allocate_memory_for_classroom("AC-202");
//     classrooms[6] = allocate_memory_for_classroom("AC-203");
//     classrooms[7] = allocate_memory_for_classroom("AC-204");

//     FILE *csv_file = fopen("database.csv", "r");
//     if (csv_file == NULL) {
//         perror("Unable to open the file :(");
//         exit(1);
//     }

//     char line[1024];
//     int column = 0, row = 0, i = 1;
//     char *class, *batch, *faculty, *time, *day, *subject;
//     char **Class_array = (char **)malloc(39 * sizeof(char *)), **Day_array = (char **)malloc(39 * sizeof(char *)), **Time_array = (char **)malloc(39 * sizeof(char *)), **Faculty_array = (char **)malloc(39 * sizeof(char *)), **Subject_array = (char **)malloc(39 * sizeof(char *)), **Batch_array = (char **)malloc(39 * sizeof(char *));

//     while(fgets(line, sizeof(line), csv_file)) {
//         column = 0;
//         row++;
//         char *token;
//         token = strtok(line, ",");
//         while(token != NULL) {
//             if (column == 0) {
//                 // strcpy(Class_array[i - 1], token);
//                 Class_array[i - 1] = token;
//                 // Class_array = realloc(Class_array, (i + 1)*sizeof(char *));
//             }

//             // Column 2
//             if (column == 1) {
//                 // Connect the classroom element with weekday
//                 // strcpy(Day_array[i - 1], token);
//                 Day_array[i - 1] = token;
//                 // Day_array = realloc(Day_array, (i + 1)*sizeof(char *));
//             }

//             // Column 3
//             if (column == 2) {
//                 // Connect the weekday with linked list of time slots
//                 // strcpy(Time_array[i - 1], token);
//                 Time_array[i - 1] = token;
//                 // Time_array = realloc(Time_array, (i + 1)*sizeof(char *));
//             }

//             // Column 4
//             if (column == 3) {
//                 // Add faculty in the node which time slot will point to
//                 // strcpy(Faculty_array[i - 1], token);
//                 Faculty_array[i - 1] = token;
//                 // Faculty_array = realloc(Faculty_array, (i + 1)*sizeof(char *));
//             }

//             // Column 5
//             if (column == 4) {
//                 // Add subject ...
//                 // strcpy(Subject_array[i - 1], token);
//                 Subject_array[i - 1] = token;
//                 // Subject_array = realloc(Subject_array, (i + 1)*sizeof(char *));
//             }

//             // Column 6
//             if (column == 5) {
//                 // Add class/division
//                 // strcpy(Batch_array[i - 1], token);
//                 Batch_array[i - 1] = token;
//                 // Batch_array = realloc(Batch_array, (i + 1)*sizeof(char *));
//             }

//             // printf("%s", token);
//             token = strtok(NULL, ", ");
//             column++;
//         }
//     }
//     for (i = 0; i < 38; i++) {
//         // printf("%s %s %s %s %s %s", Class_array[i], Day_array[i], Time_array[i], Faculty_array[i], Subject_array[i], Batch_array[i]);
//         printf("%s \n", Class_array[i]);
//     }
//     // display_Monday_schedule();


//     free(Class_array);
//     free(Day_array);
//     free(Time_array);
//     free(Faculty_array);
//     free(Subject_array);
//     free(Batch_array);
//     return 0;
// }
