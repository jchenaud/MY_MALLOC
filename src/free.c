#include "malloc.h"

void my_free(void *ptr)
{
    t_zone *tmp;
    t_zone *tmpe;
    t_zone *first;
    first = ((t_env *)glob)->tiny;
    if (ptr == NULL)
        return ;
    // printf("first  =  %p \n",first);

    tmpe = find_in_zone(ptr,first);
    size_t i = find_index_in_zone(ptr,first);
    // printf("%p\n",tmp);

    if (i != -1)//(tmp != NULL)
    {
        // printf("i find him");
        // si on garde le maillom
        // tmpe->mem = NULL;
    // show_alloc_mem();

        tmpe->size = 0;
        tmpe->used= false;
        ////ptr = NULL;
        // si on le degage
        
        tmp =  first;
        int tmpi = 0;
        // printf("%d\n",i);
    
        if(i != 0)
            while( tmpi < i -1)
            {
                // printf("%d\n",i);

                tmp = tmp->next;
                tmpi++;
            }
        tmp->next = ((t_zone*)tmp->next)->next;
        int page_size = ((t_env *)glob)->page_size;
        // printf("tmpe %p , meme %p\n",tmpe,tmpe->mem);
        printf("\n%d\n",munmap(tmpe,page_size * TINY_MULTY_PAGESIZE));
        // printf("\n%d\n",munmap(tmpe,0));

    }

}