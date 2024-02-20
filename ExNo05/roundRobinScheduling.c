#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int processNumber;
    int burstTime;
    int savedBurstTime;
    int waitingTime;
    int lastExecutedTime;
} processes[10];

int main()
{
    int previousProcess = -1, timeSlice, isProcessRemaining, processCounter;
    int currentTime = 0, i, numProcesses, totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("\n Round Robin Scheduling\n");
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    printf("Enter the time slice: ");
    scanf("%d", &timeSlice);

    printf("Enter the burst time for each process\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("\n Process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].waitingTime = processes[i].lastExecutedTime = 0;
        processes[i].processNumber = i + 1;
        processes[i].savedBurstTime = processes[i].burstTime;
    }

    printf("\nScheduling:\n");
    do
    {
        isProcessRemaining = 0;
        for (i = 0; i < numProcesses; i++)
        {
            processCounter = processes[i].burstTime;
            if (processCounter > 0)
            {
                isProcessRemaining = 1;
                processCounter = (processCounter >= timeSlice) ? timeSlice : processCounter;
                printf("\nProcess %d from %d to %d", processes[i].processNumber, currentTime, currentTime + processCounter);
                currentTime += processCounter;
                processes[i].burstTime -= processCounter;
                if (previousProcess != i)
                {
                    previousProcess = i;
                    processes[i].waitingTime += currentTime - processes[i].lastExecutedTime - processCounter;
                    processes[i].lastExecutedTime = currentTime;
                }
            }
        }
    } while (isProcessRemaining);

    // Calculation and display of total waiting time and total turnaround time may be added here

    return 0;
}
