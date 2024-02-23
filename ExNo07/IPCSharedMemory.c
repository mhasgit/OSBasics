#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SEGSIZE 100

int main(int argc, char *argv[])
{
    int sharedMemID;
    key_t key;
    char *sharedSegmentPtr;
    char message[] = "Shared message";

    // Generate a unique key
    key = ftok(".", 's');

    // Create or attach to a shared memory segment
    if ((sharedMemID = shmget(key, SEGSIZE, IPC_CREAT | IPC_EXCL | 0666)) == -1)
    {
        if ((sharedMemID = shmget(key, SEGSIZE, 0)) == -1)
        {
            perror("shmget");
            exit(1);
        }
    }
    else
    {
        printf("Creating a new shared memory segment\n");
        printf("SHMID: %d\n", sharedMemID);
    }

    // Display current shared memory segments
    system("ipcs -m");

    // Attach the shared memory segment
    if ((sharedSegmentPtr = (char *)shmat(sharedMemID, 0, 0)) == (char *)-1)
    {
        perror("shmat");
        exit(1);
    }

    // Write to the shared memory
    printf("Writing data to shared memory...\n");
    strcpy(sharedSegmentPtr, message);
    printf("DONE\n");

    // Read from the shared memory
    printf("Reading data from shared memory...\n");
    printf("DATA: %s\n", sharedSegmentPtr);
    printf("DONE\n");

    // Remove the shared memory segment
    printf("Removing shared memory segment...\n");
    if (shmctl(sharedMemID, IPC_RMID, 0) == -1)
    {
        printf("Can't remove shared memory segment...\n");
    }
    else
    {
        printf("Removed successfully\n");
    }

    return 0;
}
