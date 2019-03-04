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
    // // printf("tmp->mem = %p\n",p->mem);

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
    // // printf("fisrt  = %p\n",first);
    while (tmp->next != NULL)
    {
        // // printf("chioooo\n");

        // // printf("tmp = %p \n",tmp);
        // // printf("in\n");
        //  // printf("tmp = %p , used = %d\n",tmp->next,tmp->used);
        if(tmp->used == false)
            return(tmp);
        tmp = tmp->next;
        // if(tmp->used)
        //     // printf("end boucle\n");

        // // printf("tmp = %p,\n",tmp->next);
        // // printf("end boucle\n");
    }
    // // printf("end\n");
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

