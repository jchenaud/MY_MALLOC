/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:42:44 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 11:36:01 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		s_char_can_print_end(t_env *e, int *char_can_print_size,
	int i, int k)
{
	if (e->int_value > 0)
	{
		while (i < e->size)
		{
			k = size_wchar(e->string_wc[i]);
			(*char_can_print_size) += k;
			if (e->int_value - (*char_can_print_size) < 0)
				break ;
			i++;
		}
	}
	else
	{
		while (i < e->size)
		{
			k = size_wchar(e->string_wc[i]);
			(*char_can_print_size) += k;
			if (e->int_value + (*char_can_print_size) > 0)
				break ;
			i++;
		}
	}
}

void		s_char_can_print(t_env *e, int *char_can_print_size)
{
	int i;
	int k;

	i = 0;
	k = 0;
	e->tmp_p = e->presition;
	e->tmp_s = e->size;
	if (e->have_point == 1)
	{
		while (i < e->size)
		{
			k = size_wchar(e->string_wc[i]);
			e->presition -= k;
			if (e->presition < 0)
				break ;
			i++;
			(*char_can_print_size) += k;
		}
	}
	else
		s_char_can_print_end(e, &(*char_can_print_size), i, k);
}
