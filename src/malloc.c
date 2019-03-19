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
    // // //printf("%d",size);
    // // //printf("size allocated %d\n",size);
   return(mmap(0,size,PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE,-1,0));
   //return (NULL);
}

// void add_plage(size_t nb, t_plage *lst)
t_plage  *add_plage(size_t nb, t_plage *lst)
{
    // //printf("euuue\n");
    //printf("in_add_plage\n");

     t_plage *tmp;
     t_plage **tmp_span;
     size_t i;
     i = 0 ;
    tmp_span = (t_plage**)alloc(sizeof(t_plage)*nb+1);
    // size_t past_size = 0;

 //printf("tmp_snsize = %d   \n",sizeof(t_plage)*nb+1);

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
        // past_size = 40;

        tmp  = lst;
     tmp->next = NULL ;
     }
    //     //printf("adr = %p,tmp_spna = %p\n",adr,tmp_span);

    //  tmp_span[nb] = NULL;
    // i =1;
    //printf("in_add_plage_while i =  %zu    nb = %zu\n",i,nb);
     while (i < nb)
     {

        tmp->ptr = NULL;
        tmp->val_bigin = SIZE_MAX;
        tmp->used = false;
            // tmp_span[i] = tmp_span + (sizeof(t_plage)*i+1); // JASONITE
            //tmp_span[i] = (void*)(tmp_span + (sizeof(t_plage)*i)); // JASONITE
            tmp_span[i] = ((void*)(tmp_span) + (sizeof(t_plage)*i));
            //  //printf("plage assigner at %d  \n",(void*)(tmp_span + (sizeof(t_plage)*i)) - ((void*)(tmp_span + (sizeof(t_plage)*(i-1)))));
            //  //printf("tmp_snsize = %d   and start value is %d and t_plge_sixe = %d  \n",(sizeof(t_plage)*i),(void*)(tmp_span),(sizeof(t_plage)));
            //  //printf("past_size = %d  \n",(past_size += (sizeof(t_plage)*i) ));
            //  //printf("value i want  = %d \n", ((void*)(tmp_span)) + (sizeof(t_plage)*i));


            // ft_bzero(tmp_span[i],(sizeof(t_plage)*1));

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
    // //printf("page exit = %p\n",lst);

    //printf("out_add_plage\n");
    return (lst);
}

t_plage *get_plage()
{
    // //printf("get_plage in\n");
    t_env *e = ((t_env *)glob);
    // //printf("size %zu",e->page_size);

    t_plage *tmp;
    // //printf("get_plage in\n");

    tmp = e->buff_plage; 
    //printf("get_plage in\n");

    if( e->buff_plage->next != NULL)
        e->buff_plage =e->buff_plage->next;
    else
    {
        //intgrity_check( e->buff_plage);

        e->buff_plage = add_plage(35, e->buff_plage);
        e->buff_plage =e->buff_plage->next;
       // intgrity_check( e->buff_plage);

    }
    tmp->next = NULL;
    //printf("get_plage out\n");

    return(tmp);
}

void init_param(bool used,size_t mem_size,t_zone *p)
{
    //void ptr;
    p->next = NULL;
    p->used = used;
    printf("i exit or not %p\n",&p->mem);
    p->mem =  (void*)(&p->mem);
    // \\p->mem = sizeof(void *); //p + sizeof(t_zone); //alloc(mem_size);
    // if (p->mem == (void *) -1)
    // {
    //     // //printf("its fuking append\n");
    //     //p->mem = NULL;
    // }

    p->pla = get_plage();
   // p->pla = NULL;
    //p->pla = add_plage(10,p->pla);

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
    // tmp_span[0] = (void*)(tmp_span + (sizeof(t_zone)));
     while (i < nb_elem)
    {
        tmp->next =  tmp_span[i] = (void*)(tmp_span + (sizeof(t_zone)*i));
        // tmp->next = (t_zone *)alloc(sizeof(t_zone)*1);
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
    

    while (mem_alloc_size < page_size)
    {
        mem_alloc_size += sizeof(t_zone *);
        repeat ++;
    }
    repeat--;
     t_zone **tmp_span;

     tmp_span = (t_zone**)alloc(sizeof(t_zone)*repeat);
  

 tmp_span[0] = (void*)(tmp_span);
     lst = tmp_span[0];
     tmp = lst;
    init_param(false,mem_size,lst);
    i = 1;
    while (i < repeat)//(i < nb_elem)
    {
        tmp_span[i] = (void*)(tmp_span + (sizeof(t_zone)*i)); // JASONITE
        // tmp_span[i] = tmp_span[i-1] + (sizeof(t_zone)*i);
             
        lst->next = tmp_span[i];
        
        // lst->next = (t_zone *)alloc(sizeof(t_zone)*1);
        if (lst->next == (void *) -1 )
            return NULL;
        lst = lst->next;
        init_param(false,mem_size,lst);
        // // //printf("%d\n",lst->used);
        i++;
    }
    // // //printf("lst_count(lst) %zu \n",lst_count(lst));
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
        //printf("tmp == NULL");
        add_m_lst(NB_ADD_ZONE,size_alloc,flst);
        tmp = find_first_none_used_and_size(flst,size,size_alloc);
        if(tmp == NULL)
        {
            //printf("its apprend\n");
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
    //printf("Allocin zone return { tmp %p} ,{ptr %p},{next %p},{vbgin %d},{usesd %d},{size %d}\n",tmp,tmp->ptr,tmp->next,tmp->val_bigin,tmp->used,tmp->size);
    
    return(tmp->ptr);
} 





void *malloc(size_t size)
{
    // //printf("Zone size = %lu , plage_size  = %lu\n",sizeof(t_zone),sizeof(t_plage)*1);//40 40
    // ft_putendl("_________________________________malloc_call____ __________\n");
    
    // return NULL; 
    //  ft_putendl("_________________________________malloc_call___________ ___\n"); 
      

    int page_size;
    
    // a passer dans le point h 
    size_t N = 4096;
    size_t n = N/100;
    size_t M = N*2;
    size_t m = M/100;
    if(init == false)
        {
            // //printf("init in\n");

            t_env *e = (t_env *)alloc(sizeof(t_env)*1);
            // //printf("Buff_plage_init in\n");
            glob = e;
            e->buff_plage = NULL;
            e->buff_plage = add_plage(35,e->buff_plage);

            // //printf("Buff_plage_init out\n");

            e->page_size = getpagesize();
            e->tiny = new_lst(N);//new_lst(TINY_LS,N);
            e->small = new_lst(M);//new_lst(SMALL_LS,M);
            // //printf("EUUU\n");

            e->large = (t_zone *)alloc(sizeof(t_zone)*1);
            e->large->next = NULL;
            
            init = true;
            // write(1,"init\n",6);
        }
    page_size = ((t_env *)glob)->page_size;
    // ft_putendl("_________________________________malloc_call_INIT______________\n");

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
    // // //printf("fat\n");
    tmp = tmp->next;
    init_param(true,size,tmp);
    tmp->size =  size;
    // // //printf("voilou %p\n",tmp->mem);    
    return(tmp->mem);
}