#include <stdio.h>
#include <conio.h>

int max_matrix[100][100];
int allocation_matrix[100][100];
int need_matrix[100][100];
int available_resources[100];
int n, r;

void input();
void show();
void detect_deadlock();

int main()
{
    int i, j;
    printf("********** Deadlock Detection Algorithm ************\n");
    input();
    show();
    detect_deadlock();
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

void show()
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

void detect_deadlock()
{
    int finish[100], flag = 1, k, c1 = 0;
    int deadlock[100];
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
                        break;
                    }
                }
            }
        }
    }

    j = 0;
    flag = 0;
    for (i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            deadlock[j] = i;
            j++;
            flag = 1;
        }
    }

    if (flag == 1)
    {
        printf("\n\nSystem is in Deadlock and the Deadlock processes are:\n");
        for (i = 0; i < j; i++)
        {
            printf("P%d\t", deadlock[i]);
        }
    }
    else
    {
        printf("\nNo Deadlock Occurs");
    }
}
