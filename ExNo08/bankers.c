#include <stdio.h>
#include <conio.h>

int max_matrix[100][100];
int allocation_matrix[100][100];
int need_matrix[100][100];
int available_resources[100];
int n, r;

void input();
void display();
void calculate();

int main()
{
    int i, j;
    printf("********** Banker's Algorithm ************\n");
    input();
    display();
    calculate();
    getch();
    return 0;
}

void input()
{
    int i, j;
    printf("Enter the number of Processes\t");
    scanf("%d", &n);
    printf("Enter the number of resource instances\t");
    scanf("%d", &r);
    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &max_matrix[i][j]);
        }
    }
    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            scanf("%d", &allocation_matrix[i][j]);
        }
    }
    printf("Enter the available Resources\n");
    for (j = 0; j < r; j++)
    {
        scanf("%d", &available_resources[j]);
    }
}

void display()
{
    int i, j;
    printf("Process\t Allocation\t Max\t Available\t");
    for (i = 0; i < n; i++)
    {
        printf("\nP%d\t ", i + 1);
        for (j = 0; j < r; j++)
        {
            printf("%d ", allocation_matrix[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++)
        {
            printf("%d ", max_matrix[i][j]);
        }
        printf("\t");
        if (i == 0)
        {
            for (j = 0; j < r; j++)
                printf("%d ", available_resources[j]);
        }
    }
}

void calculate()
{
    int finish[100], flag = 1, k, c1 = 0;
    int safe[100];
    int i, j;
    for (i = 0; i < n; i++)
    {
        finish[i] = 0;
    }
    // Calculate the need matrix
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < r; j++)
        {
            need_matrix[i][j] = max_matrix[i][j] - allocation_matrix[i][j];
        }
    }
    printf("\n");
    while (flag)
    {
        flag = 0;
        for (i = 0; i < n; i++)
        {
            int c = 0;
            for (j = 0; j < r; j++)
            {
                if ((finish[i] == 0) && (need_matrix[i][j] <= available_resources[j]))
                {
                    c++;
                    if (c == r)
                    {
                        for (k = 0; k < r; k++)
                        {
                            available_resources[k] += allocation_matrix[i][j];
                            finish[i] = 1;
                            flag = 1;
                        }
                        printf("P%d->", i);
                        if (finish[i] == 1)
                        {
                            i = n;
                        }
                    }
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 1)
        {
            c1++;
        }
        else
        {
            printf("P%d->", i);
        }
    }
    if (c1 == n)
    {
        printf("\n The system is in a safe state");
    }
    else
    {
        printf("\n Processes are in a deadlock");
        printf("\n System is in an unsafe state");
    }
}
