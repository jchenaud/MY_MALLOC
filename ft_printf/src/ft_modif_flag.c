/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modif_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:37:24 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/26 11:43:23 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		easy_flag_modi(const char *str, t_env *e)
{
	if (str[e->i + 1] == ' ')
		e->have_space++;
	else if (str[e->i + 1] == '#')
		e->have_sharp = 1;
	else if (str[e->i + 1] == '.')
		e->have_point = 1;
	else if (str[e->i + 1] == 'l')
		e->have_l++;
	else if (str[e->i + 1] == 'h')
		e->have_h++;
	else if (str[e->i + 1] == 'j')
		e->have_j++;
	else if (str[e->i + 1] == '+')
		e->have_posi++;
	else if (str[e->i + 1] == 'z')
		e->have_z++;
	else
		return (0);
	return (1);
}

void	ft_modif_flag(const char *str, t_env *e)
{
	int easy;

	while (have_modi_flag(str[e->i + 1]) == 1)
	{
		easy = easy_flag_modi(str, e);
		if (easy == 0 && str[e->i + 1] == '0')
		{
			while (str[e->i + 1] == '0')
				e->i++;
			e->i--;
			e->zero++;
		}
		else if (easy == 0 && str[e->i + 1] == '-')
		{
			while (str[e->i + 2] && str[e->i + 2] == '-')
				e->i++;
			if (str[e->i + 1] && int_flag_find_without_zero(str, e->i + 1) == 1)
				return ;
			e->have_neg++;
		}
		if (str[e->i + 1])
			e->i++;
		else
			return ;
	}
}
