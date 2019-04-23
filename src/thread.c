#include "malloc.h"

static pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void lock()
{
    if(LOCK == 1)
        pthread_mutex_lock( &mutex1 );
}

void unlock()
{
    if(LOCK == 1)
         pthread_mutex_unlock( &mutex1 );
}