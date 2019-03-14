t_zone *find_first_none_used_and_size(t_zone *first,size_t size,size_t max_size) // size tail du malloc max_size taill de la plage
{
    ft_putendl("_________________________________find_first_none_used_and_size______________\n");

    t_zone *tmp;
    t_plage *tmp_p;
    tmp = first;
    while (tmp->next != NULL)
    {
    ft_putendl("_________________________________find_first_none_used_and_size_1______________\n");

        if(tmp->used == false)
        {
        ft_putendl("_________________________________find_first_none_used_and_size_2______________\n");

            tmp_p = tmp->pla;
            t_plage * tmp_plage;
            tmp_plage = tmp->pla;
            size_t plage_before = 0;
            while(tmp_plage->next != NULL)
            {
                 if(tmp_p->val_bigin == SIZE_MAX && plage_before + size  + 1 < max_size) // pa sur du +1
                 {
                    ft_putendl("never_used_plage\n");
                    return(tmp);
                    //tmp_p->val_bigin == plage_before;

                 }
                 else if(tmp_p->size >= size && tmp_p->used == false && plage_before + size  + 1 < max_size)
                 {
                    ft_putendl("used_plage\n");

                     return(tmp);
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
        ft_putendl("_________________________________find_first_none_used_and_size_RETURN_NULL______________\n");
    return NULL;
}
