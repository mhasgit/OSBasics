#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int processNumber;
    int priority;
    int burstTime;
    int waitingTime;
} ScheduledProcess;

int main()
{
    int i, j, numProcesses;
    int totalBurstTime = 0, totalWaitingTime = 0, totalTurnaroundTime = 0;
    ScheduledProcess *processes, tempProcess;

    printf("\n PRIORITY SCHEDULING.\n");
    printf("\n Enter the number of processes:\n");
    scanf("%d", &numProcesses);

    processes = (ScheduledProcess *)malloc(numProcesses * sizeof(ScheduledProcess));

    printf("Enter the burst time and priority for each process:\n");
    for (i = 0; i < numProcesses; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d %d", &processes[i].burstTime, &processes[i].priority);
        processes[i].processNumber = i + 1;
        processes[i].waitingTime = 0;
    }

    // Sorting processes based on priority
    for (i = 0; i < numProcesses - 1; i++)
    {
        for (j = i + 1; j < numProcesses; j++)
        {
            if (processes[i].priority > processes[j].priority)
            {
                tempProcess = processes[i];
                processes[i] = processes[j];
                processes[j] = tempProcess;
            }
        }
    }

    printf("\n Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < numProcesses; i++)
    {
        totalWaitingTime += processes[i].waitingTime = totalBurstTime;
        totalBurstTime += processes[i].burstTime;
        printf("\n%d\t\t%d\t\t%d\t\t%d", processes[i].processNumber, processes[i].burstTime, processes[i].waitingTime, processes[i].waitingTime + processes[i].burstTime);
    }

    totalTurnaroundTime = totalBurstTime;
    printf("\n Total waiting time: %d", totalWaitingTime);
    printf("\n Average waiting time: %f", (float)totalWaitingTime / numProcesses);
    printf("\n Total turnaround time: %d", totalTurnaroundTime);
    printf("\n Average turnaround time: %f", (float)totalTurnaroundTime / numProcesses);

    free(processes);
    return 0;
}
