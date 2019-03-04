#include "malloc.h"

#include <stdio.h>
// #include <unistd.h>   
// void **ZONE_AL = NULL;
static bool init =  false;
void *glob;
void *alloc(size_t size)
{
    // // printf("%d",size);
    // // printf("size allocated %d\n",size);
    return(mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
}


void *alloc_in_zone(t_zone *flst, size_t size_alloc,size_t size)
{
    // // printf("alloc in zone  %p\n",flst);
    t_zone *tmp;

    // // printf("size lst = %zu\n",lst_count(flst));
    // // printf("ici \n");
    tmp = find_first_none_used(flst);
    // // printf("la \n");
    if (tmp == NULL)
    {
    // // printf("/// ADDing///\n");
        
        add_m_lst(NB_ADD_ZONE,size_alloc,flst);
        tmp = find_first_none_used(flst);
        if(tmp == NULL)
        {
            // printf("caca\n");
            return NULL ;
        }
    }
    // // printf("tmp_mem = %p\n",tmp->mem);
    tmp->mem = alloc(size_alloc);
    // // printf("/// proute///\n");

    if (tmp->mem == FAIL_ALLOC)//(tmp == FAIL_ALLOC)
        tmp->mem = NULL;
    else
    {
        tmp->size = size;
        tmp->used = true;
    }
    // // printf("/// SORTIE///\n");

    return (tmp->mem);
} 
// void *save_zone(void *)
// void *ft_malloc(size_t size)
void *malloc(size_t size)
{
    // ft_putendl("_________________________________malloc_call______________\n");

    int page_size;
   // int page_size = getpagesize();
  
    if(init == false)
        {
            t_env *e = (t_env *)alloc(sizeof(t_env)*1);
            e->page_size = getpagesize();
            e->tiny = new_lst(TINY_LS,e->page_size * TINY_MULTY_PAGESIZE);
            e->small = new_lst(SMALL_LS,e->page_size * SMALL_MULTY_PAGESIZE);
            e->large = (t_zone *)alloc(sizeof(t_zone)*1);
            e->large->next = NULL;
            init = true;
            glob = e;
            write(1,"init\n",6);
        }
    page_size = ((t_env *)glob)->page_size;
    if (size < page_size * TINY_MULTY_PAGESIZE)
        return(alloc_in_zone(((t_env *)glob)->tiny,page_size * TINY_MULTY_PAGESIZE,size));
    if (size < page_size * SMALL_MULTY_PAGESIZE)
        return(alloc_in_zone(((t_env *)glob)->small,page_size * SMALL_MULTY_PAGESIZE,size));
    t_zone *tmp;
    tmp =  ((t_env *)glob)->large;
    // // printf("fat\n");
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = (t_zone *)alloc(sizeof(t_zone)*1);
    if (tmp->next == (void *) -1 )
        return(NULL) ;
    // // printf("fat\n");
    tmp = tmp->next;
    init_param(true,size,tmp);
    tmp->size =  size;
    // // printf("voilou %p\n",tmp->mem);    
    return(tmp->mem);
}



