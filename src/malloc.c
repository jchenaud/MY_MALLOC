#include "malloc.h"

static bool g_init = false;
void *alloc(size_t size)
{
   return(mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
}

void my_print_lst(t_zone **flst)
{
    t_zone *tmp = (*flst);

    int i = 0;
    printf("start_print\n");
    while(tmp != NULL)
    {
        printf("on %d element on lst \t used = %d \t next = %p \n",i,tmp->used,tmp->next);
        i++;

        tmp = tmp->next;

    }
    printf("End_print\n");

}

   void    add_one_page_zone(t_zone **flst,size_t size_alloc)
   {
       size_t reapit;
       t_zone *tmp;
        reapit = 0;
        int k = 1;
        while (reapit < 100)
        {
            reapit = (getpagesize()*k  - sizeof(t_zone)) / (sizeof(t_zone) + size_alloc); // on recupere le nobre de zone +struct que l'on peut metre dans une page en gardan une place final pour une struct
            k++;
        }
       void *p = alloc(getpagesize() * k);
       if(p == FAIL_ALLOC)
        return ;
       int i = 0;
       if((*flst) == NULL)
        {
            (*flst) = p;
            (*flst)->used = false;
            (*flst)->next =  NULL;
            (*flst)->mem = p+sizeof(t_zone);
            (*flst)->size = SIZE_MAX;
            i++;
        }
        tmp = (*flst);
        int skip = 0;
        while(tmp->next)
        {
            tmp = tmp->next;
            skip++;
        }
        tmp->next = p+sizeof(t_zone)+(size_alloc * 1);
        i=1;

       while(i < reapit)
       {
            tmp = tmp->next;
            tmp->used = false;
            tmp->mem = p+ (sizeof(t_zone)*i) +(size_alloc * (i - 1)); // -1 pour etre au debut de la zone pas a la fin
            tmp->size = SIZE_MAX;
            tmp->next = p+(sizeof(t_zone)*i)+(size_alloc * i); 
            i++;
       }
       tmp= tmp->next;
       tmp->used =  -1;
       tmp->next = NULL; 
       tmp->mem =   NULL;
       // printf("end %d tmp %p\n",i,tmp);
   }


void *alloc_in_zone(t_zone **flst, size_t size_alloc,size_t size) // ! size allonc = A N ou M ou max_val
{
    if((*flst) == NULL) // first passage
    {
      add_one_page_zone(flst,size_alloc);
    }
    t_zone *tmp; 
    tmp = (*flst);
    while(tmp){
        if(tmp->used == 0){
            tmp->used = 1;
            tmp->size = size;
            return(tmp->mem);

        }
        tmp =  tmp->next;
    }
    
    add_one_page_zone(flst,size_alloc);
    tmp = (*flst);

     while(tmp){
        if(tmp->used == 0){
            tmp->used = 1;
            tmp->size = size;
            return(tmp->mem);
        }
        tmp =  tmp->next;
    }
    
    printf("cas non prevu\n");
     return (alloc(size));
}

void *fat_alloc(size_t size)
{
    t_zone  *tmp;
    // on peut arjouter lalignement su les octer a faire aussi dans realloc
    if(!g_e.large)
    {
        g_e.large = alloc(size + sizeof(t_zone));
        if(g_e.large == FAIL_ALLOC)
            return NULL;
        g_e.large->used =  1;
        g_e.large->size = size;
        g_e.large->next = NULL;
        g_e.large->mem = (void*)g_e.large + sizeof(t_zone);
        return(g_e.large->mem);
    }
    tmp =  g_e.large;
    while(tmp->next)
       tmp = tmp->next;
    tmp->next = alloc(size + sizeof(t_zone));
    tmp =  tmp->next;
    if(tmp == FAIL_ALLOC)
        return NULL;
    tmp->used =  1;
    tmp->size = size;
    tmp->next = NULL;
    tmp->mem = (void*)tmp + sizeof(t_zone);

    return(tmp->mem);
    
    
}

void *malloc_l(size_t size)
{
    // int page_size = getpagesize();
    // ft_itoa(size);
    // ft_putendl("malloc_l");
    size =  (size + ALLIGN - 1 - ((size + ALLIGN - 1)%ALLIGN ));
    if(size == 0 )
        size = ALLIGN;
    // printf("%d\n",size);
    if(g_init == false)
    {
            g_e.tiny = NULL;
            g_e.small = NULL;
            g_e.large = NULL;
            g_init = true;
    }

    if (size <= TINY_LS)
        return(alloc_in_zone(&g_e.tiny,TINY_LS,size));//alloc_in_zone(((t_env *)glob)->tiny,n,size));
    if (size <= SMALL_LS)
        return(alloc_in_zone(&g_e.small,SMALL_LS,size));

    return(fat_alloc(size));
   //return (alloc(size));

} 

void *malloc(size_t size)
{
    //printf("COUCOU\n");
    void *r = NULL;
    lock();
    // printf("lock");

    r = malloc_l(size);
    unlock();
    // printf("unlock");

    return(r);
}