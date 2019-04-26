/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 13:19:58 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/26 10:08:57 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void my_print_lst(t_zone **flst)
{
    t_zone *tmp = (*flst);

    int i = 0;
    printf("start_print\n");
    while(tmp != NULL)
    {
        printf("on %d element on lst \t used = %d \t next = %p \n",i,tmp->used,tmp->next);
        i++;

        tmp = tmp->next;

    }
    printf("End_print\n");

}

t_zone	*find_p_in_zone(void *ptr, t_zone *flst)
{
	t_zone *tmp;

	tmp = flst;
	// printf("ici \n");
	// my_print_lst(&flst);

	while (tmp)// && tmp != 0x5252525252525252)
	{ 
		// printf("tmp %p tmp->next = %p ,tmp->mem %p ,  tmp->size =  %zu  ,used %d\n",tmp,tmp->next,tmp->mem,tmp->size,tmp->used);
		if (tmp->mem == ptr)
			return (tmp);
		tmp = tmp->next;
	}
	// printf("la2\n");

	return (NULL);
}

t_zone	*find_p(void *ptr)
{
	t_zone *r;

	r = find_p_in_zone(ptr, g_e.tiny);
	if (r != NULL)
		return (r);
	r = find_p_in_zone(ptr, g_e.small);
	if (r != NULL)
		return (r);
	r = find_p_in_zone(ptr, g_e.large);
	return (r);
}

void	free_l(void *ptr)
{
	t_zone *z;

	z = find_p(ptr);
	if (!z)
		return ;
	z->size = 0;
	z->used = 0;
}

void	free(void *ptr)
{
	lock();
	free_l(ptr);
	unlock();
}
