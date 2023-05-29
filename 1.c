#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234

typedef struct {
    int x;
} SharedData;

int main() {
    int shmid;
    SharedData *sharedData;

    // Retrieve the shared memory segment created by 2.c
    shmid = shmget(SHM_KEY, sizeof(SharedData), 0666);
    if (shmid == -1) {
        printf("Failed to retrieve the shared memory segment.\n");
        return 1;
    }

    // Attach the shared memory segment to the address space
    sharedData = (SharedData*) shmat(shmid, NULL, 0);
    if (sharedData == (SharedData*) -1) {
        printf("Failed to attach the shared memory segment.\n");
        return 1;
    }

    // Modify the value of x based on the timer in 2.c
    while (1) {
        if (sharedData->x == 10) {
            sharedData->x = 20;
        }
        // Add more conditions to change the value of x as needed
    }

    // Detach the shared memory segment
    shmdt(sharedData);

    return 0;
}
