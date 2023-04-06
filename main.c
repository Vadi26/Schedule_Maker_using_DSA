#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <signal.h>
#include <unistd.h>
#include"class_header.h"

int main() {
    FILE *fpt;

    fpt = fopen("MyFile3.csv", "r"); 
    fprintf(fpt,"ID, Name, Email, Phone Number\n");
    int id = 1000;
    char name[] = "asodfijsdof", email[] = "odsufjsoij", phone[] = "123";
    fprintf(fpt,"%d, %s, %s, %s\n", id, name, email, phone);
    fprintf(fpt,"%d, %s, %s, %s\n", id, name, email, phone);
    fclose(fpt);

    return 0;
}