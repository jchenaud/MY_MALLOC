/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 15:19:30 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/26 10:36:11 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static bool g_init = false;

void	*alloc(size_t size)
{
	void *r;

	r = mmap(0, size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (r == FAIL_ALLOC)
		r = p_erno(0);
	return (r);
}

void	page_init(t_zone **flst, size_t size_alloc, size_t reapit, void *p)
{
	t_zone	*tmp;
	int		skip;
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
	t_zone	*tmp;
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
	// my_print_lst(flst);
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

void	*alloc_in_zone(t_zone **flst, size_t size_alloc, size_t size)
{
	t_zone	*tmp;
	void	*p;

	if ((*flst) == NULL)
		add_one_page_zone(flst, size_alloc);
	p = find_not_use(flst, size);
	if (p)
		return (p);
	add_one_page_zone(flst, size_alloc);
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

void	*fat_alloc(size_t size)
{
	t_zone *tmp;

	if (!g_e.large)
	{
		g_e.large = alloc(size + sizeof(t_zone));
		if (g_e.large == NULL)
			return (NULL);
		g_e.large->used = 1;
		g_e.large->size = size;
		g_e.large->next = NULL;
		g_e.large->mem = (void*)g_e.large + sizeof(t_zone);
		return (g_e.large->mem);
	}
	tmp = g_e.large;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = alloc(size + sizeof(t_zone));
	if (tmp->next == NULL)
		return (NULL);
	tmp = tmp->next;
	tmp->used = 1;
	tmp->size = size;
	tmp->next = NULL;
	tmp->mem = (void*)tmp + sizeof(t_zone);
	return (tmp->mem);
}

void	*malloc_l(size_t size)
{
	size = (size + ALLIGN - 1 - ((size + ALLIGN - 1) % ALLIGN));
	if (size == 0)
		size = ALLIGN;
	if (g_init == false)
	{
		g_e.tiny = NULL;
		g_e.small = NULL;
		g_e.large = NULL;
		g_init = true;
	}
	if (size <= TINY_LS)
		return (alloc_in_zone(&g_e.tiny, TINY_LS, size));
	if (size <= SMALL_LS)
		return (alloc_in_zone(&g_e.small, SMALL_LS, size));
	return (fat_alloc(size));
}

void	*malloc(size_t size)
{
	void *r;

	r = NULL;
	lock();
	r = malloc_l(size);
	unlock();
	return (r);
}
