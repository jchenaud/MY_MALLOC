#include "malloc.h"

static bool init =  false;

void *alloc(size_t size)
{
    // // printf("%d",size);
    // // printf("size allocated %d\n",size);
   return(mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
   //return (NULL);
}

void add_plage(size_t nb, t_plage *lst)
{
     t_plage *tmp;
     t_plage **tmp_span;

     size_t i;

     i = 0 ;
     tmp  = lst;
    *tmp_span = (t_plage*)alloc(sizeof(t_plage)*nb);

     while (i < nb)
     {
        tmp->ptr = NULL;
        tmp->val_bigin = SIZE_MAX;
        tmp->used = false;
        tmp->next = tmp_span[i];
        // \\tmp->next = alloc(sizeof(t_plage)*1);
        if(!tmp->next)
        {
            ft_putendl("alloc erno");
            return ;
        }
        tmp = tmp->next;
        i++;
     }
     tmp->next = NULL ;
}

void init_param(bool used,size_t mem_size,t_zone *p)
{
   

    p->next = NULL;
    p->used = used;
    p->mem = alloc(mem_size);
    if (p->mem == (void *) -1)
    {
        // printf("its fuking append\n");
        p->mem = NULL;
    }
    p->pla = alloc(sizeof(t_plage)*1); // peut etre faire un span
    add_plage(10,p->pla);

    // p->pla = add_plage(100,p->pla)

    // // printf("tmp->mem = %p\n",p->mem);

}

void add_m_lst(size_t nb_elem,size_t mem_size,t_zone *lst)
{
    t_zone *tmp;
    size_t i;

    i = 0;
    tmp = lst;
    while(tmp->next != NULL)
        tmp = tmp->next;
     while (i < nb_elem)
    {
        tmp->next = (t_zone *)alloc(sizeof(t_zone)*1);
        if (tmp->next == (void *) -1 )
            return ;
        tmp = tmp->next;
        init_param(false,mem_size,tmp);
        i++;
    }
    // // printf("tmp->next =  %p for tmp = %p ,lst count %zu\n",tmp->next,tmp,lst_count(lst));
}


t_zone *new_lst(size_t nb_elem,size_t mem_size)
{
    size_t i;
    t_zone *lst;
    t_zone *tmp;

    i = 0;
    lst = (t_zone *)alloc(sizeof(t_zone *)*1);
    if (lst == (void *) -1 )
        return NULL;
    tmp = lst;
    init_param(false,mem_size,lst);
    while (i < nb_elem)
    {
        lst->next = (t_zone *)alloc(sizeof(t_zone)*1);
        if (lst->next == (void *) -1 )
            return NULL;
        lst = lst->next;
        init_param(false,mem_size,lst);
        // // printf("%d\n",lst->used);
        i++;
    }
    // // printf("lst_count(lst) %zu \n",lst_count(lst));
    return(tmp);
}



void *alloc_in_zone(t_zone *flst, size_t size_alloc,size_t size) // ! size allonc = A N ou M ou max_val
{
    // ft_putendl("_________________________________ALLOC_INZONE______________\n");

    t_plage *tmp;

    tmp = find_first_none_used_and_size(flst,size,size_alloc);
    // ft_putendl("_________________________________ALLOC_INZONE_1______________\n");

    if (tmp == NULL)
    {
        add_m_lst(NB_ADD_ZONE,size_alloc,flst);
        tmp = find_first_none_used_and_size(flst,size,size_alloc);
        if(tmp == NULL)
        {
            return NULL ;
        }
    }
    //tmp->mem = alloc(size_alloc);
    // on cherche dans la premire zone non null la premiere plage suseptible de contenire la taille voulu
    // ft_putendl("_________________________________ALLOC_INZONE_2______________\n");    
    // if (tmp->mem == FAIL_ALLOC)//(tmp == FAIL_ALLOC)
    //     tmp->mem = NULL;
    // else
    // {
    //     tmp->size = size;
    //     tmp->used = true;
    // }
    // return (tmp->mem);
    // return(tmp->mem + tmp_plage->val_bigin);
    return(tmp->ptr);
} 





void *malloc(size_t size)
{
    // printf("FUCK\n");
    // ft_putendl("_________________________________malloc_call______________\n");
    
    // return NULL;
    //  ft_putendl("_________________________________malloc_call______________\n");
     

    int page_size;
    
    // a passer dans le point h 
    size_t N = 4096;
    size_t n = N/100;
    size_t M = N*2;
    size_t m = M/100;
    if(init == false)
        {
            t_env *e = (t_env *)alloc(sizeof(t_env)*1);
            e->page_size = getpagesize();
            e->tiny = new_lst(TINY_LS,N);
            e->small = new_lst(SMALL_LS,M);
            e->large = (t_zone *)alloc(sizeof(t_zone)*1);
            e->large->next = NULL;
            init = true;
            glob = e;
            // write(1,"init\n",6);
        }
    page_size = ((t_env *)glob)->page_size;
    // ft_putendl("_________________________________malloc_call_INIT______________\n");

    if (size <= n)
        return(alloc_in_zone(((t_env *)glob)->tiny,N,size));//alloc_in_zone(((t_env *)glob)->tiny,n,size));
    if (size < (size_t)(page_size * SMALL_MULTY_PAGESIZE))
        return(alloc_in_zone(((t_env *)glob)->small,M,size));//alloc_in_zone(((t_env *)glob)->small,page_size * SMALL_MULTY_PAGESIZE,size));
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