#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int processID;
    int burstTime;
    int waitingTime;
} Process;

int main()
{
    int i, j, numProcesses, totalBurstTime = 0, totalWaitingTime = 0, totalTurnaroundTime;
    Process *processes, temp;

    printf("\n SJF Scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &numProcesses);

    processes = (Process *)malloc(numProcesses * sizeof(Process));
    printf("\nEnter the burst time for each process:\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("\nProcess %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].processID = i + 1;
        processes[i].waitingTime = 0;
    }

    // Sorting processes based on burst time
    for (i = 0; i < numProcesses; i++)
    {
        for (j = i + 1; j < numProcesses; j++)
        {
            if (processes[i].burstTime > processes[j].burstTime)
            {
                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    printf("\nProcess Scheduling:\n");
    printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for (i = 0; i < numProcesses; i++)
    {
        totalWaitingTime += processes[i].waitingTime = totalBurstTime;
        totalBurstTime += processes[i].burstTime;
        printf("\n%d\t\t%d\t\t%d\t\t%d", processes[i].processID, processes[i].burstTime, processes[i].waitingTime, processes[i].waitingTime + processes[i].burstTime);
    }

    totalTurnaroundTime = totalBurstTime + totalWaitingTime;

    printf("\nTotal waiting time: %d", totalWaitingTime);
    printf("\nAverage waiting time: %f", (float)totalWaitingTime / numProcesses);
    printf("\nTotal turnaround time: %d", totalTurnaroundTime);
    printf("\nAverage turnaround time: %f", (float)totalTurnaroundTime / numProcesses);

    free(processes);
    return 0;
}
