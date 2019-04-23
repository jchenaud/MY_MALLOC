#include "malloc.h"

void *realloc_l(void *ptr, size_t size)
{

    t_zone *z;
    void *p = NULL;
    size_t actual_size  = 0;
    // ft_putendl("realloc_l");

    // printf("Realloc is call %p \n",ptr);
    if(ptr ==NULL)
        return(malloc_l(size));

    z = find_p(ptr);
    if(z == NULL)
    {
        return (NULL);

    }

    if (size <= TINY_LS)
        actual_size = TINY_LS;
    else if (size <= SMALL_LS)
        actual_size = SMALL_LS;
    else
    {
        while(actual_size < z->size)
            actual_size += getpagesize(); 
    }
    
    if(size <= actual_size)
    {
        z->size = size;
        return(z->mem);
    }
    else
    {
       p =  malloc_l(size);
       if (p == NULL)
        return(NULL);
       ft_memcpy(p,z->mem,z->size);
       free_l((void*)z->mem);
    }
    return(p);
}

void *realloc(void *ptr, size_t size)
{
    void *r;
    lock();
    // printf("lock");
    r = realloc_l(ptr,size);
    // printf("unlock");
    unlock();

    return(r);
    
}

