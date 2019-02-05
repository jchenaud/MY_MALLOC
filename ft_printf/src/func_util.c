/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:21:20 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 23:30:09 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		int_flag(const char *str, t_env *e)
{
	int nb;

	nb = ft_int_flag_return_value(str, e->i, e);
	e->i += ft_inc_intflag(nb);
	if (e->have_point == 1)
	{
		if (nb > 0)
			e->presition = nb;
		else
			e->presition = 0;
	}
	else
	{
		if (e->have_neg)
			nb *= -1;
		e->int_value = nb;
	}
}

int			hexa_size(const char *str)
{
	int i;
	int have_oly_zero;

	have_oly_zero = 1;
	i = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') ||
		(str[i] >= 'A' && str[i] <= 'F') || (str[i] >= 'a' && str[i] <= 'f')))
	{
		if (str[i] != '0')
			have_oly_zero = 0;
		i++;
	}
	if (i == 0 || have_oly_zero == 0)
		return (i);
	return (-1);
}

int			x_point_zero(t_env *e)
{
	if (e->exa_size == -1 && e->have_point == 1)
	{
		while (e->int_value > 0)
			ft_putchar_nc_sup_int(' ', &e->int_value, e);
		if (e->exa_size == -1 && e->presition > 0)
			ft_putchar_nc('0', e);
		return (0);
	}
	return (1);
}

void		x_sharp(t_env *e, const char *str)
{
	if (e->have_sharp == 1 && e->exa_size != 0 && e->exa_size != -1)
	{
		if (((e->int_value <= e->size + 2) ||
		(e->int_value > e->presition && e->have_point == 1) || (e->zero != 0))
				&& (e->zero == 0 || e->int_value == 0 || e->have_point == 0))
		{
			if (str[e->i + 1] == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
			e->nc += 2;
			e->have_sharp = 0;
			if (e->zero != 0 || e->int_value <= e->presition + 2)
				e->sharp_size = 2;
		}
		else
			e->sharp_size = 2;
	}
}
