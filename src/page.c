/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   page.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:46:52 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/29 15:47:06 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	page_init(t_zone **flst, size_t size_alloc, size_t reapit, void *p)
{
	t_zone	*tmp;
	size_t	i;

	tmp = (*flst);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = p + sizeof(t_zone) + (size_alloc * 1);
	i = 1;
	while (i < reapit)
	{
		tmp = tmp->next;
		tmp->used = false;
		tmp->mem = p + (sizeof(t_zone) * i) + (size_alloc * (i - 1));
		tmp->size = SIZE_MAX;
		tmp->next = p + (sizeof(t_zone) * i) + (size_alloc * i);
		i++;
	}
	tmp = tmp->next;
	tmp->used = -1;
	tmp->next = NULL;
	tmp->mem = NULL;
}

void	add_one_page_zone(t_zone **flst, size_t size_alloc)
{
	size_t	reapit;
	void	*p;
	size_t	k;

	k = 1;
	reapit = 0;
	while (reapit < 100)
	{
		reapit = (getpagesize() * k - sizeof(t_zone))
			/ (sizeof(t_zone) + size_alloc);
		k++;
	}
	p = alloc(getpagesize() * k);
	if (p == NULL)
		return ;
	if ((*flst) == NULL)
	{
		(*flst) = p;
		(*flst)->used = false;
		(*flst)->next = NULL;
		(*flst)->mem = p + sizeof(t_zone);
		(*flst)->size = SIZE_MAX;
	}
	page_init(flst, size_alloc, reapit, p);
}

void	*find_not_use(t_zone **flst, size_t size)
{
	t_zone *tmp;

	tmp = (*flst);
	while (tmp)
	{
		if (tmp->used == 0)
		{
			tmp->used = 1;
			tmp->size = size;
			return (tmp->mem);
		}
		tmp = tmp->next;
	}
	return (NULL);
}
