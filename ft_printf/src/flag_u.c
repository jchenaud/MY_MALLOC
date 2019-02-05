/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 14:50:40 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/24 23:19:43 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	juste_print(t_env *e)
{
	write(1, e->ito, e->size);
	e->nc += e->size;
}

static void	first_case(t_env *e, char c)
{
	int tmp;

	tmp = e->int_value;
	while (e->int_value - e->size - e->presition > 0)
		ft_putchar_nc_sup_int(c, &e->int_value, e);
	e->int_value = tmp;
	tmp = e->presition;
	while (e->presition - e->size > 0)
		ft_putchar_nc_sup_int('0', &e->presition, e);
	e->presition = tmp;
}

static void	second_case(t_env *e)
{
	int tmp;

	tmp = e->int_value;
	while (e->int_value > e->presition && e->int_value > e->size)
		ft_putchar_nc_sup_int(' ', &e->int_value, e);
	e->int_value = tmp;
	tmp = e->presition;
	while (e->presition - e->size > 0)
		ft_putchar_nc_sup_int('0', &e->presition, e);
	e->presition = tmp;
}

void		flag_u(va_list ap, t_env *e, char u)
{
	char c;

	take_value_u(ap, e, u);
	if (e->have_point == 1 && e->presition == 0 && ft_atoi(e->ito) == 0)
		return ;
	c = (e->zero != 0) ? '0' : ' ';
	if (e->presition > e->int_value || e->presition == 0)
		first_case(e, c);
	else
		second_case(e);
	juste_print(e);
	if (e->int_value < 0 && (e->int_value * -1) > e->presition)
		while (e->int_value + e->size < 0)
			ft_putchar_nc_int(' ', &e->int_value, e);
}
