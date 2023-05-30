#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"header.h"
#include"main.c"

void displayMenu() {
    printf("Menu:\n");

    printf("1. Display Timetable\n");
    printf("2. Display class Schedule\n");
    printf("3. Display free slots\n");
    printf("4. Schedule a class\n");
    printf("5. Cancel a lecture\n");
    printf("6. Exit\n");
}

int main() {
    int choice;
    int exitFlag = 0;

    while (!exitFlag) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                //displayTimetable();
                break;
            case 2:
                //display_schedule_for_class(class_name);
                break;
            case 3:
                //display_free_slots_for_class(weekday,class_name);
		break;
	    case 4:
                //Schedule_new_lecture(faculty_name, class_name, subject);
                break;
	    case 5:
                //cancel_lecture(faculty_name, time_slot, weekday);
                break;
            case 6:
                printf("Exiting...\n");
		exitFlag = 1;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}
