#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 1234

typedef struct {
    int x;
} SharedData;

int main() {
    int shmid;
    SharedData *sharedData;

    // Create the shared memory segment
    shmid = shmget(SHM_KEY, sizeof(SharedData), IPC_CREAT | 0666);
    if (shmid == -1) {
        printf("Failed to create the shared memory segment.\n");
        return 1;
    }

    // Attach the shared memory segment to the address space
    sharedData = (SharedData*) shmat(shmid, NULL, 0);
    if (sharedData == (SharedData*) -1) {
        printf("Failed to attach the shared memory segment.\n");
        return 1;
    }

    // Timer logic
    int timer = 0;
    while (1) {
        sleep(1); // Wait for 1 second
        timer++;

        // Update the value of x in the shared memory segment
        sharedData->x = timer;

        // Add more conditions or terminate the timer as needed
    }

    // Detach the shared memory segment
    shmdt(sharedData);

    // Deallocate the shared memory segment
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
