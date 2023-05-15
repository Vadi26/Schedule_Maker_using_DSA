#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <sqlite3.h>
#define SQL_BUFFER_LENGTH 20
#define MAX_INPUT_LENGTH 20
#define MAX_MESSAGE_LENGTH 20
#define MAX_CLASSROOMS 12

struct Classroom {
    char name[20];
    int capacity;
};

struct ClassSchedule {
    char teacher_name[20];
    char classroom_name[20];
    int day;
    int start_time;
    int duration;
    struct ClassSchedule *next;
};

struct HashTable {
    struct ClassSchedule* table[MAX_CLASSROOMS];
};

int hash_function(char* str) {
    int hash_value = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        hash_value += (int) str[i];
    }
    return hash_value % MAX_CLASSROOMS;
}

void add_class_schedule(struct HashTable* ht, char* teacher_name, char* classroom_name, int day, int start_time, int duration) {
    int index = hash_function(classroom_name);
    struct ClassSchedule* new_class = (struct ClassSchedule*) malloc(sizeof(struct ClassSchedule));
    strcpy(new_class->teacher_name, teacher_name);
    strcpy(new_class->classroom_name, classroom_name);
    new_class->day = day;
    new_class->start_time = start_time;
    new_class->duration = duration;
    if (ht->table[index] == NULL) {
        ht->table[index] = new_class;
    } else {
        printf("Collision occurred\n");
    }
}

void print_class_schedule(struct HashTable* ht, char* classroom_name) {
    int index = hash_function(classroom_name);
    if (ht->table[index] == NULL) {
        printf("Class schedule for %s is empty\n", classroom_name);
    } else {
        struct ClassSchedule* temp = ht->table[index];
        while (temp != NULL) {
            if (strcmp(temp->classroom_name, classroom_name) == 0) {
                printf("Teacher: %s, Classroom: %s, Day: %d, Start Time: %d, Duration: %d\n",
                       temp->teacher_name, temp->classroom_name, temp->day, temp->start_time, temp->duration);
            }
            temp = temp->next;
        }
    }
}

void delete_class_schedule(struct HashTable* ht, char* teacher_name, char* classroom_name, int day, int start_time) {
    int index = hash_function(classroom_name);
    struct ClassSchedule* temp = ht->table[index];
    struct ClassSchedule* prev = NULL;
    while (temp != NULL) {
        if (strcmp(temp->teacher_name, teacher_name) == 0 &&
            strcmp(temp->classroom_name, classroom_name) == 0 &&
            temp->day == day && temp->start_time == start_time) {
            if (prev == NULL) {
                ht->table[index] = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Class schedule for %s at %d on day %d deleted\n", classroom_name, start_time, day);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Class schedule for %s at %d on day %d not found\n", classroom_name, start_time, day);
}

// Callback function for printing query results
static int print_callback(void *data, int argc, char **argv, char **col_names) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s = %s\n", col_names[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

// Create a new user in the database
void create_user(sqlite3* db) {
    char username[MAX_INPUT_LENGTH], password[MAX_INPUT_LENGTH];
    printf("Enter username: ");
    fgets(username, MAX_INPUT_LENGTH, stdin);
    // Remove the newline character from the end of the string
    username[strcspn(username, "\n")] = '\0';
    printf("Enter password: ");
    fgets(password, MAX_INPUT_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0';

    char sql[SQL_BUFFER_LENGTH];
    sprintf(sql, "INSERT INTO users (username, password) VALUES ('%s', '%s')", username, password);
    char* err_msg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, 0, &err_msg);
    if (rc != SQLITE_OK) {
        printf("Error creating user: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("User created successfully!\n");
    }
}

// Send a message from one user to another
void send_message(sqlite3* db) {
    char sender[MAX_INPUT_LENGTH], recipient[MAX_INPUT_LENGTH], message[MAX_MESSAGE_LENGTH];
    printf("Enter sender: ");
    fgets(sender, MAX_INPUT_LENGTH, stdin);
    sender[strcspn(sender, "\n")] = '\0';
    printf("Enter recipient: ");
    fgets(recipient, MAX_INPUT_LENGTH, stdin);
    recipient[strcspn(recipient, "\n")] = '\0';
    printf("Enter message: ");
    fgets(message, MAX_MESSAGE_LENGTH, stdin);
    message[strcspn(message, "\n")] = '\0';

    char sql[SQL_BUFFER_LENGTH];
    sprintf(sql, "INSERT INTO messages (sender, recipient, message) VALUES ('%s', '%s', '%s')", sender, recipient, message);
    char* err_msg = NULL;
    int rc = sqlite3_exec(db, sql, NULL, 0, &err_msg);
    if (rc != SQLITE_OK) {
        printf("Error sending message: %s\n", err_msg);
        sqlite3_free(err_msg);
    } else {
        printf("Message sent successfully!\n");
    }
}

// View all messages for a given user
void view_messages(sqlite3* db) {
    char username[MAX_INPUT_LENGTH];
    printf("Enter username: ");
    fgets(username, MAX_INPUT_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0';

    char sql[SQL_BUFFER_LENGTH];
    sprintf(sql, "SELECT * FROM messages WHERE recipient = '%s'", username);

    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        printf("Error preparing statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
        printf("Sender: %s\n", sqlite3_column_text(stmt, 1));
        printf("Message: %s\n\n", sqlite3_column_text(stmt, 3));
    }

    if (rc != SQLITE_DONE) {
        printf("Error retrieving messages: %s\n", sqlite3_errmsg(db));
    }

    sqlite3_finalize(stmt);
}


void main_menu(sqlite3 *db) {
    int choice;
    do {
        printf("\nWelcome to ChatGPT\n");
        printf("1. Create new user\n");
        printf("2. Send message\n");
        printf("3. View messages\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                create_user(db);
                break;
            case 2:
                send_message(db);
                break;
            case 3:
                view_messages(db);
                break;
            case 4:
                printf("\nGoodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    sqlite3 *db;
    char *err_msg = 0;

    // Open the database
    int rc = sqlite3_open("schedule.db", &db);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        return 1;
    }

    // Create the classrooms table
    // char *sql = "CREATE TABLE classrooms ("
    //             "id INTEGER PRIMARY KEY,"
    //             "name TEXT,"
    //             "capacity INTEGER"
    //             ");";
    // rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "SQL error: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    //     sqlite3_close(db);
    //     return 1;
    // }

    // // Insert some classrooms
    // sql = "INSERT INTO classrooms (name, capacity) VALUES "
    //       "('Room A-101', 30),"
    //       "('Room A-102', 25),"
    //       "('Room A-103', 35),"
    //       "('Room A-104', 20),"
    //       "('Room A-201', 40),"
    //       "('Room A-202', 30),"
    //       "('Room A-203', 25),"
    //       "('Room A-204', 20),"
    //       "('Room A-301', 45),"
    //       "('Room A-302', 35),"
    //       "('Room A-303', 30),"
    //       "('Room A-304', 25);";
    // rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "SQL error: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    //     sqlite3_close(db);
    //     return 1;
    // }

    // // Create the class_schedule table
    // sql = "CREATE TABLE class_schedule ("
    //       "id INTEGER PRIMARY KEY,"
    //       "teacher_name TEXT,"
    //       "classroom_id INTEGER,"
    //       "day INTEGER,"
    //       "start_time INTEGER,"
    //       "duration INTEGER,"
    //       "FOREIGN KEY (classroom_id) REFERENCES classrooms(id)"
    //       ");";
    // rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "SQL error: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    //     sqlite3_close(db);
    //     return 1;
    // }

    // // Insert some class schedules
    // sql = "INSERT INTO class_schedule (teacher_name, classroom_id, day, start_time, duration) VALUES "
    //       "('John Doe', 1, 1, 9, 2),"
    //       "('Jane Smith', 2, 1, 9, 2),"
    //       "('Bob Johnson', 3, 1, 11, 1),"
    //       "('Alice Lee', 4, 1, 11, 1),"
    //       "('John Doe', 5, 1, 12, 1)";
    
    // rc = sqlite3_exec(db, sql, 0, 0, &err_msg);
    // if (rc != SQLITE_OK) {
    //     fprintf(stderr, "SQL error: %s\n", err_msg);
    //     sqlite3_free(err_msg);
    //     sqlite3_close(db);
    //     return 1;
    // }

    // Call the main menu function
    main_menu(db);

    // Close the database
    sqlite3_close(db);

    return 0;
}