#include <stdio.h>
#include <stdlib.h>

int semaphore = 1, itemsProduced = 0, capacity = 3, itemCount = 0;

void producer()
{
    semaphore = wait(semaphore);
    itemsProduced = signal(itemsProduced);
    capacity = wait(capacity);
    itemCount++;
    printf("\nProducer produces the item %d", itemCount);
    semaphore = signal(semaphore);
}

void consumer()
{
    semaphore = wait(semaphore);
    itemsProduced = wait(itemsProduced);
    capacity = signal(capacity);
    printf("\nConsumer consumes item %d", itemCount);
    itemCount--;
    semaphore = signal(semaphore);
}

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

int main()
{
    int choice;
    printf("\n1. Producer\n2. Consumer\n3. Exit\n");
    while (1)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if ((semaphore == 1) && (capacity != 0))
                producer();
            else
                printf("Buffer is full");
            break;
        case 2:
            if ((semaphore == 1) && (itemsProduced != 0))
                consumer();
            else
                printf("Buffer is empty");
            break;
        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}
