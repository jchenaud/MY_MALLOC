#include "malloc.h"

static bool init =  false;

void intgrity_check(t_plage *plage)
{
// //printf("tmp_p = %p ,  and next = %p \n",tmp_p,tmp_p->next);
       
        t_plage *tmp_p =  plage;
        t_plage *tmp_p_tmp;

        while(tmp_p->next != NULL)
        {
             tmp_p_tmp = tmp_p;
             tmp_p = tmp_p->next;

            if(tmp_p  == tmp_p_tmp)
            {
                //printf("____________________________________________________Not itegre\n");
               return;
            }
        }
     //printf("_________________________________________________itegre\n");

}

void *alloc(size_t size)
{
   return(mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
}

// void add_plage(size_t nb, t_plage *lst)
t_plage  *add_plage(size_t nb, t_plage *lst)
{
     t_plage *tmp;
     t_plage **tmp_span;
     size_t i;
     i = 0 ;
    tmp_span = (t_plage**)alloc(sizeof(t_plage)*nb+1);
     if(lst != NULL)
     {
        tmp  = lst;
        while(tmp->next != NULL)
            tmp = tmp->next;
     }
     else{
         tmp_span[0] = (void*)(tmp_span + (sizeof(t_plage))+1);
         lst = tmp_span[0];
         i++;
        tmp  = lst;
     tmp->next = NULL ;
     }
     while (i < nb)
     {

        tmp->ptr = NULL;
        tmp->val_bigin = SIZE_MAX;
        tmp->used = false;
        tmp_span[i] = ((void*)(tmp_span) + (sizeof(t_plage)*i));
        tmp->next = tmp_span[i];
        if(!tmp->next)
        {
            ft_putendl("alloc erno");
            return (NULL);
        }
        tmp = tmp->next;
        i++;
     }
     tmp->next = NULL ;
    return (lst);
}

t_plage *get_plage()
{
    t_env *e = ((t_env *)glob);
    t_plage *tmp;
    tmp = e->buff_plage; 
    if( e->buff_plage->next != NULL)
        e->buff_plage =e->buff_plage->next;
    else
    {
        e->buff_plage = add_plage(35, e->buff_plage);
        e->buff_plage =e->buff_plage->next;
    }
    tmp->next = NULL;
    return(tmp);
}

void init_param(bool used,size_t mem_size,t_zone *p)
{
    p->next = NULL;
    p->used = used;
  //  printf("i exit or not %p\n",&p->mem);
    p->mem =  (void*)(&p->mem);
    p->pla = get_plage();

}

void add_m_lst(size_t nb_elem,size_t mem_size,t_zone *lst)
{
    t_zone *tmp;
    t_zone **tmp_span;

    size_t i;

    i = 0;
    tmp = lst;
    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp_span = (t_zone**)alloc(sizeof(t_zone)*nb_elem);
     while (i < nb_elem)
    {
        tmp->next =  tmp_span[i] = (void*)(tmp_span + (sizeof(t_zone)*i));
        if (tmp->next == (void *) -1 )
            return ;
        tmp = tmp->next;
        init_param(false,mem_size,tmp);
        i++;
    }
}


t_zone *new_lst(size_t mem_size)
{ //465
    size_t i;
    t_zone *lst; 
    t_zone *tmp;

    i = 0;
    size_t mem_alloc_size = 0;
    size_t page_size = getpagesize();
    size_t repeat = 0;
    
    printf("T_z size =  %lu \n",sizeof(t_zone));

    repeat = (page_size / sizeof(t_zone));
    // while (mem_alloc_size < page_size)
    // {
    //     mem_alloc_size += (sizeof(t_zone *)*1);
    //     repeat ++;
    // }
    // printf("coucou2\n");

    // repeat--;
     t_zone **tmp_span;

     tmp_span = (t_zone**)alloc(sizeof(t_zone *)*repeat);
  

    tmp_span[0] = (void*)(tmp_span); 
     lst = tmp_span[0];
     tmp = lst;
    init_param(false,mem_size,lst);
    i = 1;
    printf("repeat = %lu\n",repeat);
    printf("%d , page_size = %d , t_zone  * repet = %d \n",repeat,page_size,repeat * sizeof(t_zone *));

    while (i < repeat -1)
    {
        tmp_span[i] = (void*)(tmp_span + (sizeof(t_zone)*i +1)); // JASONITE
       printf("ACUTAL POS = %lu\n",(void*)(tmp_span[i-1]) + (sizeof(t_zone)));
       // tmp_span[i] = (void*)(tmp_span[0]) + (sizeof(t_zone)*i);
       // tmp_span[i] = (void*)(tmp_span[i-1]) + (sizeof(t_zone));

        // if(!tmp_span[i])
        //     printf("WTF\n");
        // else
        // {
                printf("%p\n",tmp_span[i]);
        // }
            

        lst->next = tmp_span[i];
        if (lst->next == (void *) -1 )
            return NULL;
        lst = lst->next;
        init_param(false,mem_size,lst);
        i++;

   // printf("coucou4 %d\n",i);

    }
     //printf('%p\n', tmp);

    printf("end %d\n",i);

    return(tmp);
}



void *alloc_in_zone(t_zone *flst, size_t size_alloc,size_t size) // ! size allonc = A N ou M ou max_val
{
    ft_putendl("_________________________________ALLOC_INZONE______________\n");

    t_plage *tmp;

    tmp = find_first_none_used_and_size(flst,size,size_alloc);
    ft_putendl("_________________________________ALLOC_INZONE_1______________\n");

    if (tmp == NULL)
    {
        add_m_lst(NB_ADD_ZONE,size_alloc,flst);
        tmp = find_first_none_used_and_size(flst,size,size_alloc);
        if(tmp == NULL)
        {
            printf("its apprend\n");
            return NULL ;
        }
    }
    ft_putendl("_________________________________ALLOC_INZONE_Return______________\n");
    printf("%p\n",tmp->ptr);
    return(tmp->ptr);
} 





void *malloc(size_t size)
{
    //  ft_putendl("_________________________________malloc_call___________ ___\n"); 
      
    int page_size;
    size_t N = 4096;
    size_t n = N/100;
    size_t M = N*2;
    size_t m = M/100;
    if(init == false)
        {

            t_env *e = (t_env *)alloc(sizeof(t_env)*1);
            glob = e;
            e->buff_plage = NULL;
            e->buff_plage = add_plage(35,e->buff_plage);
            e->page_size = getpagesize();
            e->tiny = new_lst(N);//new_lst(TINY_LS,N);
            e->small = new_lst(M);//new_lst(SMALL_LS,M);
            e->large = (t_zone *)alloc(sizeof(t_zone)*1);
            e->large->next = NULL;
            init = true;
        }
    page_size = ((t_env *)glob)->page_size;
    // ft_putendl("_________________________________malloc_call_INIT______________\n");

    printf("size  = %d\n",size);
    if (size <= n)
        return(alloc_in_zone(((t_env *)glob)->tiny,N,size));//alloc_in_zone(((t_env *)glob)->tiny,n,size));
    if (size < m)
        return(alloc_in_zone(((t_env *)glob)->small,M,size));//alloc_in_zone(((t_env *)glob)->small,page_size * SMALL_MULTY_PAGESIZE,size));
    t_zone *tmp;
    tmp =  ((t_env *)glob)->large;
    printf("fat\n");
    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = (t_zone *)alloc(sizeof(t_zone)*1);
    if (tmp->next == (void *) -1 )
        return(NULL) ;
    tmp = tmp->next;
    init_param(true,size,tmp);
    tmp->size =  size;
    return(tmp->mem);
}