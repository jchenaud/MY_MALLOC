/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:37:20 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/24 16:12:48 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	juste_print(t_env *e)
{
	if (e->have_sharp == 1)
	{
		if ((ft_atoi(e->ito) != 0) &&
			(e->have_point == 0 || e->size >= e->presition))
			ft_putchar_nc('0', e);
		else if (e->have_point == 0 && e->int_value != 0)
			ft_putchar_nc(' ', e);
	}
	if (ft_atoi(e->ito) != 0 || e->have_point == 0 || e->have_sharp == 1)
	{
		write(1, e->ito, e->size);
		e->nc += e->size;
	}
	else if (e->have_point == 1 && ft_atoi(e->ito) == 0
		&& e->int_value != 0 && e->presition == 0)
		ft_putchar_nc(' ', e);
}

void		flag_o_first_part(t_env *e, char c, int *place_zero, int abs)
{
	int tmp_presition;

	if (e->int_value > 0 && e->have_neg != 0)
		e->int_value *= -1;
	abs = e->int_value;
	if (e->int_value < 0)
		abs *= -1;
	if ((e->have_point == 1) && (e->presition > abs || e->presition > e->size))
	{
		if (e->presition < abs)
		{
			while (e->presition < e->int_value)
				if (e->have_neg == 0)
					ft_putchar_nc_sup_int(' ', &e->int_value, e);
				else
					ft_putchar_nc_sup_int(c, &e->int_value, e);
		}
		tmp_presition = e->presition;
		while (e->presition > e->size)
			ft_putchar_nc_pres_int('0', &(*place_zero), e);
		while (ft_atoi(e->ito) == 0 && e->presition > 0 &&
			e->int_value >= 0 && tmp_presition > 1 && e->have_sharp == 0)
			ft_putchar_nc_sup_int('0', &e->presition, e);
		e->presition = tmp_presition;
	}
}

void		flag_o_cor(t_env *e, char c)
{
	int size_sharp;
	int place_zero;
	int abs;

	abs = 0;
	place_zero = 0;
	size_sharp = 0;
	if ((e->have_sharp) != 0)
		size_sharp = 1;
	flag_o_first_part(e, c, &place_zero, abs);
	if (e->have_neg == 0)
	{
		if (c == '0' && e->have_point == 1 && e->presition == 0)
			c = ' ';
		while (e->int_value - size_sharp - e->size - place_zero > 0)
			ft_putchar_nc_sup_int(c, &e->int_value, e);
	}
	juste_print(e);
	if (size_sharp == 1 && ft_atoi(e->ito) == 0)
		size_sharp = 0;
	while (e->int_value + e->size + size_sharp + place_zero < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}

void		flag_o(va_list ap, t_env *e, char flag)
{
	char c;

	take_value_o(ap, e, flag);
	if ((e->zero > 0) && (ft_atoi(e->ito) != 0 || (e->have_point == 0)))
		c = '0';
	else
		c = ' ';
	if (e->int_value == 0 && e->have_point == 0)
	{
		juste_print(e);
		return ;
	}
	else
		flag_o_cor(e, c);
}
