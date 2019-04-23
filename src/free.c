#include "malloc.h"

t_zone *find_p_in_zone(void *ptr, t_zone *flst)
{
    t_zone *tmp;

    tmp = flst;
    while(tmp){
        if(tmp->mem == ptr)
            return(tmp);
        tmp = tmp->next;
    }
    return(NULL);
}

t_zone *find_p(void *ptr)
{
    t_zone *r;

    r = find_p_in_zone(ptr,g_e.tiny);
    if(r != NULL)
        return(r);
    r = find_p_in_zone(ptr,g_e.small);
     if(r != NULL)
        return(r);
    r = find_p_in_zone(ptr,g_e.large);
    return(r);
    
}

void free_l(void *ptr)
{
    t_zone *z;

    z = find_p(ptr);
    if(!z)
        return;
    z->size = 0;
    z->used = 0;
}

void free(void *ptr)
{
    lock();
    free_l(ptr);
    unlock();
}