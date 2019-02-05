/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_d_anex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:09:52 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 22:14:11 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	juste_print(t_env *e)
{
	if (e->have_point == 0 && difzero(e->ito, e->size) == 0)
	{
		write(1, e->ito, e->size);
		e->nc++;
	}
	else if (difzero(e->ito, e->size) == 1)
	{
		if (e->ito_neg == 1 || e->ito_neg == 0)
		{
			write(1, e->ito, e->size);
			e->nc += e->size;
		}
		else if (difzero(e->ito, e->size) == 1)
		{
			write(1, &e->ito[1], e->size - 1);
			e->nc += e->size - 1;
		}
	}
}

void		flag_d_neg_end(t_env *e, int *modi_size, int *mod_pres, char c)
{
	if (e->have_posi > 0 && ft_atoi(e->ito) >= 0)
	{
		if (c == '0')
		{
			ft_putchar_nc('+', e);
			e->have_posi = 0;
		}
		(*modi_size)++;
	}
	while (e->int_value - e->size - (*modi_size) - (*mod_pres) > 0)
		ft_putchar_nc_sup_int(c, &e->int_value, e);
	if (e->have_posi != 0 && ft_atoi(e->ito) >= 0 && c == ' ')
	{
		if ((e->have_point == 0 || e->presition < e->int_value))
			ft_putchar_nc_int('+', &(*modi_size), e);
	}
	if ((*mod_pres) != 0)
		while ((*mod_pres) > 0)
			ft_putchar_nc_sup_int('0', &(*mod_pres), e);
	juste_print(e);
	if (e->int_value < 0 && e->have_posi != 0)
		ft_putchar_nc(' ', e);
	while (e->int_value + e->size + (*modi_size) < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}

void		flag_d_neg(t_env *e, int *modi_size, int *mod_pres, char c)
{
	int tmp;

	if ((e->zero > 0) && ((ft_atoi(e->ito) != 0 && e->presition == 0)
		|| (ft_atoi(e->ito) == 0 && ((e->have_point == 0
			|| (e->have_point == 1 && e->presition != 0))))))
		c = '0';
	else
		c = ' ';
	if (e->have_point == 1 &&
		(e->int_value <= 0 || e->int_value < e->presition))
	{
		tmp = (*modi_size);
		if (e->have_posi != 0)
		{
			ft_putchar_nc_int('+', &tmp, e);
			e->have_posi = 0;
		}
		while (e->presition - e->size - (*modi_size) > 0)
			ft_putchar_nc_pres_int('0', &tmp, e);
		(*modi_size) = tmp;
	}
	else if (e->have_point == 1 && e->presition > e->size)
		(*mod_pres) = e->presition - e->size;
	flag_d_neg_end(e, &(*modi_size), &(*mod_pres), c);
}

void		flag_d_pos_end(t_env *e, int *modi_size, int *mod_pres)
{
	if (e->ito_neg == 1)
	{
		ft_putchar_nc('-', e);
		e->ito_neg = 2;
	}
	if ((*mod_pres) != 0)
		while ((*mod_pres) > 0)
			ft_putchar_nc_sup_int('0', &(*mod_pres), e);
	juste_print(e);
	while (e->int_value + e->size + (*modi_size) < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}

void		flag_d_pos(t_env *e, int *modi_size, int *mod_pres, char c)
{
	int tmp;

	if (e->have_point == 1 &&
		(e->int_value <= 0 || e->int_value < e->presition))
	{
		tmp = (*modi_size);
		ft_putchar_nc_int('-', &e->presition, e);
		e->ito_neg = 2;
		while (e->presition - e->size - (*modi_size) > 0)
			ft_putchar_nc_pres_int('0', &tmp, e);
		(*modi_size) = tmp;
	}
	else if (e->have_point == 1 && e->presition > e->size)
		(*mod_pres) = e->presition - e->size + 1;
	if (c == '0' && ft_atoi(e->ito) < 0 && e->ito_neg == 1)
	{
		ft_putchar_nc('-', e);
		e->ito_neg = 2;
	}
	while (e->int_value - e->size - (*modi_size) - (*mod_pres) > 0)
		ft_putchar_nc_sup_int(c, &e->int_value, e);
	flag_d_pos_end(e, &(*modi_size), &(*mod_pres));
}
