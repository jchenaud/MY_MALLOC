/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:50:27 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 22:16:31 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			difzero(char *n, int s)
{
	if (ft_atoi(n) == 0 && s == 1)
		return (0);
	return (1);
}

static int	zero_case_particularity(t_env *e)
{
	if (e->zero != 0 && e->have_posi != 0 && e->int_value > 0
		&& e->have_point == 1 && e->presition < e->int_value)
	{
		e->nc += e->int_value - 1;
		while (e->int_value - e->presition - 2 > 0)
		{
			ft_putchar(' ');
			e->int_value--;
		}
		ft_putchar('+');
		e->int_value--;
		while (e->int_value - 1 > 0)
		{
			ft_putchar('0');
			e->int_value--;
		}
		return (-1);
	}
	return (0);
}

static int	zero_case_d(t_env *e, int *modi_size)
{
	if (difzero(e->ito, e->size) == 0)
	{
		if (e->have_point == 1 && e->int_value > e->presition)
			ft_putchar_nc(' ', e);
		if (e->have_space != 0)
		{
			ft_putchar_nc(' ', e);
			(*modi_size)++;
		}
		if (e->zero != 0 && e->have_posi != 0 && e->int_value > 0
			&& e->have_point == 0)
		{
			ft_putchar_nc('+', e);
			while (e->int_value - 1 > 0)
			{
				ft_putchar_nc('0', e);
				e->int_value--;
			}
			return (-1);
		}
		return (zero_case_particularity(e));
	}
	return (0);
}

void		flag_d(va_list ap, t_env *e)
{
	int		modi_size;
	int		mod_pres;
	char	c;

	c = 0;
	modi_size = 0;
	mod_pres = 0;
	take_value_d(ap, e);
	if (e->have_space != 0 && ft_atoi(e->ito) > 0
		&& e->have_posi == 0 && e->have_point == 0)
	{
		ft_putchar(' ');
		e->nc++;
		modi_size++;
	}
	if (zero_case_d(e, &modi_size) != 0)
		return ;
	if ((e->zero > 0) && (e->presition == 0 || e->presition < e->int_value))
		c = '0';
	else
		c = ' ';
	if (e->ito_neg == 0)
		flag_d_neg(e, &modi_size, &mod_pres, c);
	else
		flag_d_pos(e, &modi_size, &mod_pres, c);
}
