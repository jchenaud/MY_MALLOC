/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 16:28:50 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 17:36:05 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_init(t_env *e)
{
	e->presition = 0;
	e->int_value = 0;
	e->have_sharp = 0;
	e->have_l = 0;
	e->have_int = 0;
	e->have_point = 0;
	e->have_neg = 0;
	e->have_write = 0;
	e->have_posi = 0;
	e->have_space = 0;
	e->zero = 0;
	e->sub_n_zero = 0;
	e->have_h = 0;
	e->have_j = 0;
	e->have_z = 0;
	e->ito_neg = 0;
	e->exa_size = 0;
	e->sharp_size = 0;
	if (e->ito != NULL)
	{
		free(e->ito);
		e->ito = NULL;
	}
}

static int		ft_protect(const char *str, t_env *e)
{
	if (!str[e->i + 1])
		return (-1);
	if (e->have_l != 0 && e->have_h != 0)
	{
		if (str[e->i + 1] == 'd')
			e->have_h = 0;
		else
			return (-1);
	}
	if (e->have_j != 0 && e->have_h != 0 && str[e->i + 1] != 'd')
		return (-1);
	if (e->have_j != 0 && e->have_h != 0)
		e->have_h = 0;
	if (e->have_j != 0 && e->have_z != 0 && str[e->i + 1] != 'd')
		return (-1);
	if (e->have_j != 0 && e->have_z != 0)
		e->have_z = 0;
	if (e->have_h != 0 && e->have_z != 0)
		e->have_h = 0;
	return (0);
}

static int		ft_check_flag_first_part(const char *str, va_list ap, t_env *e)
{
	if (str[e->i + 1] == '%')
		flag_pc(e);
	else if (str[e->i + 1] == 'x' || str[e->i + 1] == 'X')
		x_flag(str, ap, e);
	else if (str[e->i + 1] == 'o' || str[e->i + 1] == 'O')
		flag_o(ap, e, str[e->i + 1]);
	else if (str[e->i + 1] == 'd'
		|| str[e->i + 1] == 'i' || str[e->i + 1] == 'D')
	{
		if (str[e->i + 1] == 'D')
			e->have_l = 2;
		else if (str[e->i + 1] == 'l')
			e->have_l = 0;
		flag_d(ap, e);
	}
	else if (str[e->i + 1] == 's')
		flag_s(e, ap, 's');
	else if (str[e->i + 1] == 'S')
		flag_s(e, ap, 'S');
	else if (str[e->i + 1] == 'p')
		flag_p(ap, e);
	else
		return (0);
	return (1);
}

static void		not_realflag(t_env *e, const char *str)
{
	char c;

	c = ' ';
	if (e->zero)
		c = '0';
	while (e->int_value - 1 > 0)
		ft_putchar_nc_sup_int(c, &e->int_value, e);
	ft_putchar(str[e->i + 1]);
	e->nc++;
	while (e->int_value + 1 < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}

int				ft_check_flag(const char *str,
	unsigned int init, va_list ap, t_env *e)
{
	if (init == 1)
		ft_init(e);
	init = 0;
	ft_modif_flag(str, e);
	if (ft_protect(str, e) == -1)
		return (-1);
	if (ft_check_flag_first_part(str, ap, e) == 1)
		return (0);
	else if (str[e->i + 1] == 'C' || str[e->i + 1] == 'c')
	{
		if (flag_uni_c(e, ap, str[e->i + 1]) == -1)
			return (-1);
	}
	else if (int_flag_find(str, e->i) == 1)
	{
		int_flag(str, e);
		ft_check_flag(str, 0, ap, e);
	}
	else if (str[e->i + 1] == 'u' || str[e->i + 1] == 'U')
		flag_u(ap, e, str[e->i + 1]);
	else
		not_realflag(e, str);
	return (0);
}
