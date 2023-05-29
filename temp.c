#include <stdio.h>
#include <time.h>

int main() {
    while (1) {
        // Get the current time
        time_t currentTime = time(NULL);

        // Convert the current time to a string representation
        char* dateTimeString = ctime(&currentTime);

        // Clear the console (for Unix/Linux/macOS)
        // printf("\033[H\033[J");

        // Print the current time
        printf("Current Time: %s", dateTimeString);

        // Wait for 1 second before updating the time
        // Adjust the sleep duration as desired for a smoother display
        // (Note: this sleep function is platform-dependent)
        sleep(1);
    }

    return 0;
}
