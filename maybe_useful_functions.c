void fill_classrooms_in_array() {
    FILE *file = fopen("database.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return; 
    }

    char line[100];
    char *token;
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        token = strtok(line, ",");
        if (token != NULL) {
            // i++;
            // if (does_string_exist_in_array(token) == 1);
            if (does_string_exist_in_array(token) == 0 || does_string_exist_in_array(token) == -1) {
                // printf("Hona work!!! \n");
                CLASS_ROOMS[i] = token;
                i++;
            }
        }
    }
    // for(i = )
    fclose(file);
}

// \brief Utility function which returns 1 if the provided string is present in array
int does_string_exist_in_array(char *token) {
    if (CLASS_ROOMS[0] == NULL) return -1;
    for (int i = 0; i < 8; i++) {
        if(!strcmp(CLASS_ROOMS[i], token)) return 1;
    }
    return 0;
}