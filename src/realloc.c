#include "malloc.h"

void *realloc(void *ptr, size_t size)
{

    t_zone *z;
    void *p = NULL;
    size_t actual_size  = 0;

    // printf("Realloc is call %p \n",ptr);
    if(ptr ==NULL)
        return(malloc(size));

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
       p =  malloc(size);
       ft_memcpy(p,z->mem,z->size);
       free((void*)z->mem);
    }
    return(p);
}
