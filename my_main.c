#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct ll_node {
    char *CLASS;
    char *DAY;
    char *SUBJECT;
    char *TIME_SLOT;
    char *CLASS_ROOM;
    char *FACULTY;
    struct ll_node *next, *prev;
}ll_node;

ll_node *createNode() {
    ll_node *newNode = NULL;
    newNode = (ll_node *)malloc(sizeof(ll_node));
    // newNode->CLASS = class;
    // newNode->DAY = day;
    // newNode->SUBJECT = subject;
    // newNode->TIME_SLOT = time_slot;
    // newNode->CLASS_ROOM = class_room;
    // newNode->FACULTY = faculty;
    newNode->next = newNode->prev = NULL;

    return newNode;
}

ll_node *csv_to_LL(FILE *csv_file) {
    char line[200];
    char *token;
    int i = 0;
    ll_node *head = NULL;
    // head = (ll_node *)malloc(sizeof(ll_node));
    while (fgets(line, sizeof(line), csv_file)) {
        token = strtok(line, ",");
        if (head == NULL) {
            ll_node *newNode = createNode();
            head = newNode;
            while (token != NULL) {
                switch (i) {
                    case 0:
                        newNode->CLASS = token;
                        i++;
                    case 1:
                        newNode->DAY = token;
                        i++;
                    case 2:
                        newNode->SUBJECT = token;
                        i++;
                    case 3:
                        newNode->TIME_SLOT = token;
                        i++;
                    case 4:
                        newNode->CLASS_ROOM = token;
                        i++;
                    case 5:
                        newNode->FACULTY = token;
                        i++;
                }
                token = strtok(NULL, ",");
            }
        }
        else {
            ll_node *latest_node = head;
            while (latest_node->next) {
                latest_node = latest_node->next;
            }
            ll_node *newNode = (ll_node *)malloc(sizeof(ll_node));
            newNode->prev = latest_node;
            latest_node->next = newNode;
            while (token != NULL) {
                switch (i) {
                    case 0:
                        newNode->CLASS = token;
                        i++;
                    case 1:
                        newNode->DAY = token;
                        i++;
                    case 2:
                        newNode->SUBJECT = token;
                        i++;
                    case 3:
                        newNode->TIME_SLOT = token;
                        i++;
                    case 4:
                        newNode->CLASS_ROOM = token;
                        i++;
                    case 5:
                        newNode->FACULTY = token;
                        i++;
                }
                token = strtok(NULL, ",");
            }
        }
        i = 0;
    }
    return head;
}

void printLL(ll_node *head) {
    ll_node *ptr = head;
    while (ptr) {
        printf("%s   %s   %s   %s   %s   %s", ptr->CLASS, ptr->DAY, ptr->SUBJECT, ptr->TIME_SLOT, ptr->CLASS_ROOM, ptr->FACULTY);
        ptr = ptr->next;
        printf("\n");
    }
}

int main() {
    int user;
    FILE *database = fopen("database.csv", "r");

    // int id;
    // printf("Enter your id : ");
    // scanf("%d", &id);
    // if (id >=0 && id <= 10) user = 1;
    // else user = 0;

    ll_node *head = NULL;
    head = csv_to_LL(database);
    // char *class = "SY COMP", *day = "MON", *subject = "DSA", *time_slot = "9-10", *class_room = "AC-101", *faculty = "XYZ";
    // ll_node *newNode = createNode(class, day, subject, time_slot, class_room, faculty);
    // printf("%s %s %s %s %s %s", newNode->CLASS, newNode->DAY, newNode->SUBJECT, newNode->TIME_SLOT, newNode->CLASS_ROOM, newNode->FACULTY);
    printLL(head);
    return 0;
}