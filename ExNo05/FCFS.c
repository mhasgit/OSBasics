#include <stdio.h>
#include <stdlib.h>

struct Process
{
    int processID;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
} processes[10];

int main()
{
    int i, numberOfProcesses;
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    printf("\n FCFS Scheduling...\n");
    printf("Enter the number of processes: ");
    scanf("%d", &numberOfProcesses);

    for (i = 0; i < numberOfProcesses; i++)
    {
        processes[i].processID = i + 1;
        printf("\nBurst time of process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
    }

    // Calculating waiting time and turnaround time for the first process
    processes[0].waitingTime = 0;
    processes[0].turnaroundTime = processes[0].burstTime;
    totalTurnaroundTime = processes[0].turnaroundTime;

    // Calculating waiting time and turnaround time for each subsequent process
    for (i = 1; i < numberOfProcesses; i++)
    {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }

    // Printing waiting time and turnaround time for each process
    for (i = 0; i < numberOfProcesses; i++)
    {
        printf("\nWaiting time for process %d: %d", processes[i].processID, processes[i].waitingTime);
        printf("\nTurnaround time for process %d: %d\n", processes[i].processID, processes[i].turnaroundTime);
    }

    printf("\nTotal waiting time: %d", totalWaitingTime);
    printf("\nAverage waiting time: %f", (float)totalWaitingTime / numberOfProcesses);
    printf("\nTotal turnaround time: %d", totalTurnaroundTime);
    printf("\nAverage turnaround time: %f", (float)totalTurnaroundTime / numberOfProcesses);

    return 0;
}
