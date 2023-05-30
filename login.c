#include <stdio.h>
#include <string.h>

int Teacher(const char* password) {
    const char* TeacherPass = "coep123";
    if (strcmp(password, TeacherPass) == 0)
        return 1;
    else
    	    return 0;
}

int Student(const char* password) {
    const char* StudentPass = "student";
    if (strcmp(password, StudentPass) == 0)
        return 1;
    else
        return 0;
}

int main() {
    char username[20];
    char password[20];
    int role;

    printf("Login Page\n");
    printf("==========\n");

    printf("Select Role:\n");
    printf("1. Teacher\n");
    printf("2. Student\n");
    printf("Enter your choice: ");
    scanf("%d", &role);
    
    if (role == 1) 
    {
	printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        
	if (Teacher(password))
            printf("Teacher login successful. Welcome, %s!\n", username);
        else
            printf("Invalid teacher credentials. Login failed.\n");
    }
    else if (role == 2) 
    {
        printf("Username: ");
        scanf("%s", username);
        printf("Password: ");
        scanf("%s", password);
        
	if (Student(password))
            printf("Student login successful. Welcome, %s!\n", username);
        else 
		printf("Invalid student credentials. Login failed.\n");
    }
    else
        printf("Invalid role selection. Login failed.\n");
    return 0;
}
