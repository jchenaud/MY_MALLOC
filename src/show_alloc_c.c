/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 15:40:42 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/29 15:40:47 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t	print_line_info_c(t_zone *tmp)
{
	ft_puthexa(tmp);
	ft_putstr(" -> ");
	ft_puthexa(tmp->mem);
	ft_putstr(" : ");
	ft_putnbr(tmp->size);
	ft_putstr(" octets -> ");
	ft_putstr((const char*)tmp->mem);
	ft_putstr("\n\t");
	return (tmp->size);
}

size_t	print_mem_zone_content(t_zone *first)
{
	t_zone *tmp;
	size_t octes;

	octes = 0;
	tmp = first;
	if (!first)
		return (0);
	while (tmp->next != NULL)
	{
		if (tmp->used == true)
		{
			octes += print_line_info_c(tmp);
		}
		else if (tmp->used == -1)
		{
			ft_putstr("\n\t");
			ft_puthexa(tmp);
			ft_putstr("\n\t");
		}
		tmp = tmp->next;
	}
	ft_putchar('\n');
	return (octes);
}

void	show_alloc_mem_content(void)
{
	size_t octes;

	ft_putstr("\n");
	ft_putstr("TINY : ");
	ft_puthexa(g_e.tiny);
	ft_putstr("\n\t");
	octes = print_mem_zone_content(g_e.tiny);
	ft_putstr("SMALL : ");
	ft_puthexa(g_e.small);
	ft_putstr("\n\t");
	octes += print_mem_zone_content(g_e.small);
	ft_putstr("LARGE : ");
	ft_puthexa(g_e.large);
	ft_putstr("\n\t");
	octes += print_mem_zone_content(g_e.large);
	ft_putstr("Total : ");
	ft_putnbr(octes);
	ft_putstr(" octets\n");
}
