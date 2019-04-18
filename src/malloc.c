#include "malloc.h"

static bool g_init = false;
t_env g_e;
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
        printf("on %d element on lst \t used = %d \t\n",i,tmp->used);
        i++;
        tmp = tmp->next;
    }
}

   void    add_one_page_zone(t_zone **flst,size_t size_alloc)
   {
       size_t reapit;
       t_zone *tmp;
    
       printf("get_p_size %zu,t_zone size %zu, size_aloc %zu , flst = %p\n",getpagesize(),sizeof(t_zone),size_alloc , *flst);
       reapit = (getpagesize()  - sizeof(t_zone)) / (sizeof(t_zone) + size_alloc); // on recupere le nobre de zone +struct que l'on peut metre dans une page en gardan une place final pour une struct
      // printf("ripeat = %zu\n",reapit);
       void *p = alloc(getpagesize());

       // tmp  = flst;

        int i = 0;

     // printf("p = %p\n ",p);
        if((*flst) == NULL)
        {
            printf("TMP = NULL\n");
            (*flst) = p;
            (*flst)->used = false;
            (*flst)->next =  NULL;
            (*flst)->mem = p+sizeof(t_zone);
            (*flst)->size = SIZE_MAX;
            i++;
           // printf("TMP = NULL _ out\n");

        }
        printf("end %d Flst %p\n",i,*flst);

        tmp = (*flst);
        
        tmp->next = p+sizeof(t_zone)+(size_alloc * i);
        i=1;

       while(i < reapit)
       {
           // printf("ici ? %d\n",i);
            tmp = tmp->next;
            tmp->used = false;
            tmp->mem = p+ (sizeof(t_zone)*i) +(size_alloc * (i - 1)); // -1 pour etre au debut de la zone pas a la fin
            tmp->size = SIZE_MAX;
            tmp->next = p+(sizeof(t_zone)*i)+(size_alloc * i); 
            i++;
            //printf("end ? %d\n",i);

       }
       tmp= tmp->next;
       tmp->used =  -1;
       tmp->next = NULL; 

        printf("end %d Flst %p\n",i,*flst);
       //return flst;
       
   }


void *alloc_in_zone(t_zone *flst, size_t size_alloc,size_t size) // ! size allonc = A N ou M ou max_val
{
    printf("alloc_in_zone_is_call flst =  %p\n",flst);

    if(flst == NULL) // first passage
    {
      add_one_page_zone(&flst,size_alloc);
      my_print_lst(&flst);
    }
    printf("flst %p , tiny %p \n",flst,g_e.tiny);
    t_zone *tmp; 
    tmp = flst;
    while(tmp){
        if(tmp->used == 0){
            tmp->used = 1;
            tmp->size = size;
            return(tmp->mem);
        }
    }
    
    printf("cas non prevu\n");
    return (alloc(size));
}


void *malloc(size_t size)
{
   // printf("MY_malloc_is_call\n");
    int page_size = getpagesize();
    size_t N = page_size;
    size_t n = 7;
    size_t M = N*2;
    size_t m = M/100;
    //void  *glob;
    if(g_init == false)
    {
            g_e.tiny = NULL;
            g_e.small = NULL;
            g_e.large = NULL;
            g_init = true;
       //     printf("alloc finit\n");
    }
    //g_e.tiny= alloc(sizeof(t_zone));
  //  printf("%p\n",((t_env *)glob)->tiny->next);

    if (size <= n)
        return(alloc_in_zone(g_e.tiny,n,size));//alloc_in_zone(((t_env *)glob)->tiny,n,size));
    if (size < m)
        return(alloc_in_zone(g_e.small,m,size));
    return (alloc(size));

}