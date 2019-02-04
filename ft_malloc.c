#include "malloc.h"

#include <stdio.h>
#include <unistd.h>

// void **ZONE_AL = NULL;
static bool init =  false;
void *glob;
void *alloc(size_t size)
{
    // printf("%d",size);
    // printf("size allocated %d\n",size);
    return(mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
}


void *alloc_in_zone(t_zone *flst, size_t size)
{
    t_zone *tmp;
    tmp = find_first_none_used(flst);
    tmp->mem = alloc(size);
    if (tmp == FAIL_ALLOC)
        tmp->mem = NULL;
    else
        tmp->used = true;
    printf("%p\n",tmp->mem);
    return (tmp->mem);
}
// void *save_zone(void *)
void *ft_malloc(size_t size)
{
    int page_size = getpagesize();
  
    if(init == false)
        {
            t_env *e = (t_env *)alloc(sizeof(t_env)*1);
            e->tiny = new_lst(TINY_LS,page_size * TINY_MULTY_PAGESIZE);
            e->small = new_lst(SMALL_LS,page_size * SMALL_MULTY_PAGESIZE);
            init = true;
            glob = e;
        }
    if (size < page_size * TINY_MULTY_PAGESIZE)
        return(alloc_in_zone(((t_env *)glob)->tiny,page_size * TINY_MULTY_PAGESIZE));
    if (size < page_size * SMALL_MULTY_PAGESIZE)
    {
        printf("page_size = %d\n",page_size);
        return(alloc_in_zone(((t_env *)glob)->small,page_size * SMALL_MULTY_PAGESIZE));
    }
    printf("pas encore coder");
}



