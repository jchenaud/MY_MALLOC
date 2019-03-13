#include "malloc.h"


            // t_env *e = (t_env *)alloc(sizeof(t_env)*1);

size_t lst_count(t_zone *lst)
{
    size_t i;
    t_zone *tmp;

    i = 0;
    tmp =  lst;
    while(tmp->next)
    {
        tmp = tmp->next;
        i++;
    }
    return (i);
}

void init_param_old(bool used,size_t mem_size,t_zone *p)
{
    p->next = NULL;
    p->used = used;
    p->mem = alloc(mem_size);
    if (p->mem == (void *) -1)
    {
        // printf("its fuking append\n");
        p->mem = NULL;
    }
    // // printf("tmp->mem = %p\n",p->mem);

}

void add_m_lst_old(size_t nb_elem,size_t mem_size,t_zone *lst)
{
    t_zone *tmp;
    int i;

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



t_zone *new_lst_old(size_t nb_elem,size_t mem_size)
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
        // // printf("%d\n",lst->used);
        i++;
    }
    // // printf("lst_count(lst) %zu \n",lst_count(lst));
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

t_zone *find_first_none_used_and_size(t_zone *first,size_t size,size_t max_size) // size tail du malloc max_size taill de la plage
{
    t_zone *tmp;
    t_plage *tmp_p;
    tmp = first;
    while (tmp->next != NULL)
    {
        if(tmp->used == false)
        {
            tmp_p = tmp->pla;
            t_plage * tmp_plage;
            tmp_plage = tmp->pla;
            size_t plage_before = 0;
            while((tmp_p->val_bigin != SIZE_MAX) || !(tmp_p->size >= size && tmp_p->used == false))
            {
                plage_before += tmp_plage->size;
                tmp_plage = tmp_plage->next;
            }
            if(plage_before + size < max_size)
                return(tmp);// on pourait si on refait une structure retourner avec la plage
        }
        tmp = tmp->next;
    }
    return NULL;
}


/* recherche ptr dans une zone pour la retourner et modifie sa taille en fonction des maillon libre persu */
t_zone *find_in_zone(void *ptr, t_zone *first)
{
    t_zone *tmp;
    tmp = first;
    int i;

    i = 0;
    while (tmp->mem != ptr)
    {
        // // printf("%p // %p\n",tmp,ptr);
        if (tmp->next != NULL)
            tmp = tmp->next;
        else
        {
            // // printf("pas ici\n");

            return(NULL);
        }
        // if(tmp->used == false)
        //     i++;
    }
    // // printf("normall out\n");
    // tmp->size = i;
    return tmp;
}

size_t find_index_in_zone(void *ptr, t_zone *first)
{
    t_zone *tmp;
    tmp = first;
    size_t i;

    i = 0;
    while (tmp->mem != ptr)
    {
        //  // printf("%p // %p\n",tmp->mem,ptr);
        if (tmp->next != NULL)
            tmp = tmp->next;
        else
        {
            // // printf("pas ici\n");

            return(-1);
        }
        i++;
        // if(tmp->used == false)
        //     i++;
    }
    // // printf("normall out\n");
    // tmp->size = i;
    return i;
}

