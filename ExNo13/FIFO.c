#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 0, m, n, rs[30], flag = 1, p[30], pageFaults = 0, fifoIndex = 0;
    // Removed unnecessary variables and initialized pageFaults and fifoIndex for clarity

    system("clear"); // or use system("cls") on Windows
    printf("FIFO Page Replacement Algorithm\n");
    printf("Enter the number of frames: ");
    scanf("%d", &n);

    printf("Enter the reference string (end with -1): "); // Changed termination condition to -1 for clarity

    while (1)
    {
        scanf("%d", &rs[i]);
        if (rs[i] == -1) // Changed termination condition to -1 for clarity
            break;
        i++;
    }

    m = i; // Number of pages in the reference string

    // Initialize frame array to -1 to indicate empty frames
    for (i = 0; i < n; i++)
        p[i] = -1;

    for (i = 0; i < m; i++)
    {
        flag = 1;
        // Check if the current page is already in one of the frames
        for (int j = 0; j < n; j++)
        {
            if (p[j] == rs[i])
            {
                printf("Data already in page\n");
                flag = 0;
                break;
            }
        }
        // If the page is not in any frame, replace the page in the FIFO order
        if (flag == 1)
        {
            p[fifoIndex] = rs[i];
            fifoIndex = (fifoIndex + 1) % n; // Move FIFO index in a circular manner
            pageFaults++;

            for (int j = 0; j < n; j++)
            {
                if (p[j] != -1) // Check if frame is not empty before printing
                    printf("\nPage %d: %d", j + 1, p[j]);
                else
                    printf("\nPage %d: Empty", j + 1);

                if (p[j] == rs[i])
                    printf(" *"); // Mark the recently added page
            }
            printf("\n\n");
        }
    }

    printf("Total number of page faults = %d\n", pageFaults);

    return 0;
}
