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
    printf("euuue\n");

     t_plage *tmp;
      t_plage **tmp_span;

     size_t i;

     i = 0 ;
     tmp  = lst;
     tmp_span = (t_plage**)alloc(sizeof(t_plage)*nb+1);
    void *adr = &tmp_span;
    //     printf("adr = %p,tmp_spna = %p\n",adr,tmp_span);

    //  tmp_span[nb] = NULL;
    // i =1;
     while (i < nb)
     {

        tmp->ptr = NULL;
        tmp->val_bigin = SIZE_MAX;
        tmp->used = false;
        
            void *adr = &tmp_span;
            // tmp_span[i] = tmp_span + (sizeof(t_plage)*i+1); // JASONITE
            tmp_span[i] = (void*)(tmp_span + (sizeof(t_plage)*i+1)); // JASONITE

            //tmp_span[i] = (t_plage **)(adr) + (sizeof(t_plage)*i+1); // JASONITE

            // adr += (sizeof(t_plage));
            // tmp_span[i] = adr;
        //tmp_span[i] = adr + (sizeof(t_plage*)*i+1);
        // printf("v1 = %lu , v2 = %lu\n",tmp_span + (sizeof(t_plage)*i+1),adr + (sizeof(t_plage*)*i+1));
        //  printf(" tmp_span[i] = %p, adrspna = %p\n", tmp_span[i],adr + (sizeof(t_plage)*(i+1)));
         printf("sizeof span [%d] \n",i);//, sizeof addr %d\n",sizeof(tmp_span),sizeof(adr));


        // tmp_span[i] = *(tmp_span + (sizeof(t_plage)*i+1));
        // printf(" i ===== %p,%p\n",tmp_span[i],tmp_span);
        // adr = adr + (sizeof(t_plage)*i+1);
        // tmp_span[i] = adr ; //mmap(tmp_span[i],(sizeof(t_plage)*1),PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0);
        tmp->next = tmp_span[i];
        //  printf("plopp [%d] \n",i);//, sizeof addr %d\n",sizeof(tmp_span),sizeof(adr));

        // tmp->next = alloc(sizeof(t_plage)*1);
        if(!tmp->next)
        {
            ft_putendl("alloc erno");
            return ;
        }
        //  printf("pp [%d] \n",i);//, sizeof addr %d\n",sizeof(tmp_span),sizeof(adr));

        tmp = tmp->next;
        i++;
        //  printf("vichy [%d] \n",i);//, sizeof addr %d\n",sizeof(tmp_span),sizeof(adr));

     }
     tmp->next = NULL ;
        //  printf("karamool[%d] \n",i);//, sizeof addr %d\n",sizeof(tmp_span),sizeof(adr));

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
{ //465
    size_t i;
    t_zone *lst; 
    t_zone *tmp;

    i = 0;
    // size_t mem_alloc_size;
    // size_t page_size = getpagesize();
    // size_t repeat = 0;
    // while (mem_alloc_size < page_size)
    // {
    //     mem_alloc_size += sizeof(t_zone *);
    //     repeat ++;
    // }
    // repeat--;
    // t_zone **tmp_span;
    // tmp_span = (t_zone**)alloc(sizeof(t_plage)*repeat);
    lst = (t_zone *)alloc(sizeof(t_zone *)*1);
    if (lst == (void *) -1 )
        return NULL;
    tmp = lst;
    // lst = tmp_span[0];
    init_param(false,mem_size,lst);
    // i = 1;
    while (i < nb_elem)//(i < nb_elem)
    {
        // tmp_span[i] = tmp_span[i-1] + (sizeof(t_zone)*i);
        // lst->next = tmp_span[i];
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