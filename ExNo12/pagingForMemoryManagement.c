#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threads[2];
int counter;
pthread_mutex_t lock;

void *do_some_job(void *arg)
{
    pthread_mutex_lock(&lock);
    unsigned long i = 0;
    counter += 1;
    printf("\nJob %d started\n", counter);

    for (i = 0; i < (0xFFFFFFFF); i++)
        ; // Simulate some work

    printf("\nJob %d finished\n", counter);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
    int i = 0;
    int err;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("\nMutex initialization failed\n");
        return 1;
    }

    while (i < 2)
    {
        err = pthread_create(&(threads[i]), NULL, &do_some_job, NULL);
        if (err != 0)
            printf("\nCan't create thread: [%s]", strerror(err));
        i++;
    }

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
