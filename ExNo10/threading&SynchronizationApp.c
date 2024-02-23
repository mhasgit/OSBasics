#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[2];

void *do_something(void *arg)
{
    unsigned long i = 0;
    pthread_t thread_id = pthread_self();

    if (pthread_equal(thread_id, threads[0]))
    {
        printf("\nFirst thread processing\n");
    }
    else
    {
        printf("\nSecond thread processing\n");
    }

    for (i = 0; i < (0xFFFFFFFF); i++)
        ;

    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    while (i < 2)
    {
        err = pthread_create(&(threads[i]), NULL, &do_something, NULL);
        if (err != 0)
            printf("\nCan't create thread: [%s]", strerror(err));
        else
            printf("\nThread created successfully\n");

        i++;
    }

    sleep(5);

    return 0;
}
