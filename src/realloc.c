/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 13:36:40 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/25 15:29:09 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc_l(void *ptr, size_t size)
{
	t_zone	*z;
	void	*p;
	size_t	actual_size;

	p = NULL;
	actual_size = 0;
	if (ptr == NULL)
		return (malloc_l(size));

	
	z = find_p(ptr);

	if (z == NULL)
		return (rea_undifined());
	actual_size = z->size;
	size_t actual_range = 0;
	if(actual_size > SMALL_LS)
	{
		while (actual_range < actual_size)
		{
			actual_range += getpagesize();
		}
	}

	// else
	size_t alloc_size = (size + ALLIGN - 1 - ((size + ALLIGN - 1) % ALLIGN));
	if((actual_size <= TINY_LS && alloc_size <= TINY_LS) || (actual_size <= SMALL_LS && alloc_size <= SMALL_LS)  || (actual_range > alloc_size))
	{
		// ft_putendl("yo");
		z->size = size;
	 	return (z->mem);
	}
	else
	{
		// ft_putendl("coucou");
		p = malloc_l(size);
		if (p == NULL)
		{
			// ft_putendl("realloc_fail");

			return (NULL);
		}
		ft_memcpy(p, z->mem, z->size);
		// ft_putendl("ft_memcpy");

		free_l((void*)z->mem);
	}
	return (p);
}

void	*realloc(void *ptr, size_t size)
{
	void *r;

	r = NULL;
	lock();
	r = realloc_l(ptr, size);
	unlock();
	return (r);
}

