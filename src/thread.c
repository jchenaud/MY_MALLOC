#include "malloc.h"

static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void lock()
{
   // printf("lock\n");

    pthread_mutex_lock( &mutex1 );

}

void unlock()
{
    // printf("unlock\n");

     pthread_mutex_unlock( &mutex1 );
    // printf("unlock after\n");

}