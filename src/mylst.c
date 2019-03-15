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



t_zone *new_lst_old(size_t nb_elem,size_t mem_size)
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

t_plage *find_first_none_used_and_size(t_zone *first,size_t size,size_t max_size) // size tail du malloc max_size taill de la plage
{
    // ft_putendl("_________________________________find_first_none_used_and_size______________\n");

    t_zone *tmp;
    t_plage *tmp_p;
    tmp = first;
    while (tmp->next != NULL)
    {
    // ft_putendl("_________________________________find_first_none_used_and_size_1______________\n");

        if(tmp->used == false)
        {
        // ft_putendl("_________________________________find_first_none_used_and_size_2______________\n");

            tmp_p = tmp->pla;
            t_plage * tmp_plage;
            tmp_plage = tmp->pla;
            size_t plage_before = 0;
            while(tmp_plage->next != NULL)
            {
                 if(tmp_p->val_bigin == SIZE_MAX && plage_before + size  + 1 < max_size) // pa sur du +1
                 {
                    // ft_putendl("never_used_plage\n");
                    tmp_p->val_bigin = plage_before;
                    tmp_p->ptr = tmp->mem + plage_before + 1;
                    tmp_p->size = size;
                    tmp_p->used = true;
                    return(tmp_p);

                 }
                 else if(tmp_p->size >= size && tmp_p->used == false && plage_before + size  + 1 < max_size)
                 {
                    // ft_putendl("used_plage\n");
                    tmp_p->size = size;
                    tmp_p->used = true;
                    return(tmp_p);
                 }
                 plage_before += tmp_plage->size;
                 tmp_plage = tmp_plage->next;

            }
            // while((tmp_p->val_bigin != SIZE_MAX) && !(tmp_p->size >= size && tmp_p->used == false))
            // {
            // //ft_putendl("_________________________________find_first_none_used_and_size_3______________\n");
            //     printf("valbigin = %d\n,size = tmp_size = %zu && %d,\n",tmp_p->val_bigin,tmp_p->size,SIZE_MAX);
            //     // if(tmp_p->val_bigin == SIZE_MAX)
            //     //     printf ("WHUUUU\n");
            //     plage_before += tmp_plage->size;
            //     tmp_plage = tmp_plage->next;
            // }
            // if(plage_before + size < max_size)
            // {
            //     ft_putendl("_________________________________find_first_none_used_and_size_4______________\n");

            //     return(tmp);// on pourait si on refait une structure retourner avec la plage
            // }
        }
        tmp = tmp->next;
    }
        // ft_putendl("_________________________________find_first_none_used_and_size_RETURN_NULL______________\n");
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

