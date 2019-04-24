/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erno.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:13:56 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/24 15:36:56 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	erno(int i)
{
	if (ERROR == 1)
	{
		ft_putstr("malloc Error : it appears mmap cannot allocate ");
		ft_putchar(i + 48);
		ft_putchar('\n');
	}
}

void	*p_erno(int i)
{
	if (ERROR == 1)
	{
		ft_putstr("malloc Error : it appears mmap dont allocate  Code = ");
		ft_putchar(i + 48);
		ft_putchar('\n');
	}
	return (NULL);
}

void	*rea_undifined(void)
{
	if (ERROR == 1)
	{
		ft_putstr("Realloc Error : it appears you tried");
		ft_putendl(" to modify a pointer not allocated with this malloc");
	}
	return (NULL);
}
