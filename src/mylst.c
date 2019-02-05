#include "malloc.h"


            // t_env *e = (t_env *)alloc(sizeof(t_env)*1);

void init_param(bool used,size_t mem_size,t_zone *p)
{
    p->used = used;
    p->mem = alloc(mem_size);
    if (p->mem == (void *) -1)
    {
        printf("its fuking append\n");
        p->mem = NULL;
    }
    p->next = NULL;
}

void add_m_lst(size_t nb_elem,size_t mem_size,t_zone *lst)
{
    t_zone *tmp;
    int i;

    i = 0;
    tmp = lst;
    while(tmp->next != NULL)
        tmp = tmp->next;
     while (i < nb_elem)
    {
        lst->next = (t_zone *)alloc(sizeof(t_zone)*1);
        if (lst->next == (void *) -1 )
            return ;
        lst = lst->next;
        init_param(false,mem_size,lst);
        i++;
    }
}



t_zone *new_lst(size_t nb_elem,size_t mem_size)
{
    int i;
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
        // printf("%d\n",lst->used);
        i++;
    }
    // printf("%d\n",i);
    return(tmp);
}

t_zone *find_first_none_used(t_zone *first)
{
    t_zone *tmp;
    tmp = first;
    while (tmp->next != NULL)
    {
        if(tmp->used == false)
            return(tmp);
        tmp = tmp->next;
    }
    return NULL;
}