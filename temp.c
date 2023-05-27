#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *TIME_SLOTS[10] = {"08:00-09:00", "09:00-10:00", "10:00-11:00", "11:00-12:00", "12:00-13:00", "13:00-14:00", "14:00-15:00", "15:00-16:00", "16:00-17:00", "17:00-18:00"};

int main() {
    char faculty[10] = "balle";
    strcpy(faculty, NULL);
    printf("%s", faculty);
    return 0;
}