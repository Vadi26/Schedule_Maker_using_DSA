#include<stdio.h>
#include<stdlib.h>

typedef struct CLASS {
    char name[20];
    int projector;        // 1 for 'projector available', 0 for 'projector not available
    // int vacancy;          // 1 for 'class available', 0 for 'class not available
    int capacity;
}CLASS;

typedef struct teacher {
    CLASS *classroom;
    SUBJECTS *teacher_subject;
    BRANCH_AND_YEAR *branch_and_year;
    TIMING *timing;
}teacher;

typedef struct SUBJECTS {
    char subject_name[];
}SUBJECTS;

typedef struct BRANCH_AND_YEAR {
    char branch[];
    int year;
    int division;
}BRANCH_AND_YEAR;

typedef struct TIMING {
    int lecture_time;
}TIMING;

// typedef struct FACULTY {
//     char name[50];
//     int id;              // It is kinda the roll no of teacher(by which we will get to know that this is a teacher and not a student, coz a student will have different format of roll no)
//     int subject_code;    // We will have code for each subject and this will contain the subject code of the subject that this teacher is teaching
//     CLASS *class_room;
// }FACULTY;