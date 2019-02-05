/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:07:29 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/24 16:19:25 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	normal_case(t_env *e)
{
	int i;

	write(1, "0x", 2);
	e->nc += 2;
	i = 0;
	if (e->have_point == 1 && e->presition > e->int_value)
	{
		while (e->presition - e->size > 0)
			ft_putchar_nc_sup_int('0', &e->presition, e);
	}
	write(1, e->ito, e->size);
	e->nc += e->size;
	e->size += 2;
}

static	void	null_case(t_env *e)
{
	int pres;

	if (e->have_point == 1 && e->presition < 3 && e->presition > 0)
		pres = e->presition;
	else if (e->have_point == 1 && e->presition == 0)
		pres = 2;
	else
		pres = 3;
	write(1, "0x0", pres);
	e->nc += pres;
	e->size = pres;
}

void			flag_p(va_list ap, t_env *e)
{
	e->ito = ft_llitoa_base((long long unsigned int)
		(va_arg(ap, long long unsigned int)), 16, 0);
	e->size = ft_strlen(e->ito);
	if (e->zero == 0)
		while (e->int_value > e->size + 2)
			ft_putchar_nc_sup_int(' ', &e->int_value, e);
	if (ft_atoi(e->ito) != 0)
		normal_case(e);
	else
		null_case(e);
	if (e->zero != 0)
		while (e->int_value > e->size)
			ft_putchar_nc_sup_int('0', &e->int_value, e);
	if (e->presition != 0 && e->presition > e->int_value)
		while (e->presition - (e->size - 2) > 0)
			ft_putchar_nc_sup_int('0', &e->presition, e);
	while (e->int_value + e->size < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}
