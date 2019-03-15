#include "malloc.h"


void ft_desaloc(void *ptr,size_t len)
{
    
    int debug = munmap(ptr,len);
    // if (debug == -1)
    //     // printf("munmap erno\n");
}

int find_desaloc(t_zone *first,void *ptr,size_t len)
{
    t_zone *tmpe;
    t_zone *tmp;

    size_t i;

    t_zone *debug;

    // first = ((t_env *)glob)->tiny;
    tmpe = find_in_zone(ptr,first);
        if (tmpe != NULL)
        {
            i = find_index_in_zone(ptr,first);
            // // printf("i find him");
        // si on garde le maillom
        // tmpe->mem = NULL;
        // show_alloc_mem();
        // tmpe->size = 0;
        // tmpe->used= false;
        ////ptr = NULL;
        // si on le degage
        tmp =  first;
        int tmpi = 0;
    
        if(i != 0 )
        {
            while( tmpi < i -1)
            {
                tmp = tmp->next;
                tmpi++;
            }
            if(tmp->next != NULL)
            {
                debug = ((t_zone*)tmp->next);
            // // printf("tmp = %p\n",tmp);
            // // printf("tmp_sup = %p\n",tmp->next);
            // // printf("tmp_decal = %p\n",((t_zone*)tmp->next)->next);
                tmp->next = ((t_zone*)tmp->next)->next;
            }
        }
        else
             if(tmp->next != NULL)
             {
                  // printf("first  = %p\n",first);
                tmp = first->next;
                first=NULL;
                ft_desaloc(first,sizeof(t_zone)*1); //tmpe ,len
                // // printf("coucou\n");
                first = tmp;
                // printf("Nfirst  = %p\n",first);
                
                 return 0;

             }
            else
                // printf("case \n"); 
        ft_desaloc(tmpe,(sizeof(t_zone)*1)); //tmpe ,len
        return 1;
    
    // // printf("lst_count(lst) %zu \n",lst_count(first));

        }
    return 0;

}

// void my_free(void *ptr)
void free(void *ptr)
{
    // ft_putendl("_________________________________Free_call______________\n");

    t_zone *tmp;
    t_zone *tmpe;
    t_zone *first;
    int page_size = ((t_env *)glob)->page_size;
    if (ptr == NULL)
        return ;
    // // printf("begin OF FREE\n");
    first = ((t_env *)glob)->tiny;    
    if (find_desaloc(first,ptr,page_size * TINY_MULTY_PAGESIZE) == 1)
    {
        // // printf("first_out  = %p\n",first);

        //  // printf("END OF FREE\n");
        return ;
    }
    first = ((t_env *)glob)->small;
    if (find_desaloc(first,ptr,page_size * SMALL_MULTY_PAGESIZE) == 1)
    {
        // printf("first_out  = %p\n",first);

        //  // printf("END OF FREE\n");
        return ;
    }
    first = ((t_env *)glob)->large;    
    if (find_desaloc(first,ptr,0) == 1)
    {
        // // printf("first_out  = %p\n",first);

        //  // printf("END OF FREE\n");
        return ;
    }
    
    // // printf("END OF FREE\n");
    // // printf("lst_count(lst) %zu \n",lst_count(first));





    
    

    // // printf("first  =  %p \n",first);

    // tmpe = find_in_zone(ptr,first);
    // size_t i = find_index_in_zone(ptr,first);
    // // printf("%p\n",tmp);

    // if (i != -1)//(tmp != NULL)
    // {
    //     // // printf("i find him");
    //     // si on garde le maillom
    //     // tmpe->mem = NULL;
    // // show_alloc_mem();

    //     tmpe->size = 0;
    //     tmpe->used= false;
    //     ////ptr = NULL;
    //     // si on le degage
        
    //     tmp =  first;
    //     int tmpi = 0;
    //     // // printf("%d\n",i);
    
    //     if(i != 0)
    //         while( tmpi < i -1)
    //         {
    //             // // printf("%d\n",i);

    //             tmp = tmp->next;
    //             tmpi++;
    //         }
    //     tmp->next = ((t_zone*)tmp->next)->next;
    //     int page_size = ((t_env *)glob)->page_size;
    //     // // printf("tmpe %p , meme %p\n",tmpe,tmpe->mem);
    //     // printf("\n%d\n",munmap(tmpe,page_size * TINY_MULTY_PAGESIZE));
    //     // // printf("\n%d\n",munmap(tmpe,0));

    //}

}