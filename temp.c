#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *TIME_SLOTS[10] = {"08:00-09:00", "09:00-10:00", "10:00-11:00", "11:00-12:00", "12:00-13:00", "13:00-14:00", "14:00-15:00", "15:00-16:00", "16:00-17:00", "17:00-18:00"};

int main() {
    int time_slot_index[10];
    int *p = time_slot_index[0];
    for(int i = 0; i < 10; i++) {
        p = i;
        p++;
    }
    for (int i = 0; i < 10; i++) printf("%d \n", time_slot_index[i]);
    return 0;
}