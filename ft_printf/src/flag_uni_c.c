/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_uni_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 12:53:56 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/26 11:52:11 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			size_wchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		if (MB_CUR_MAX >= 1)
			return (1);
	}
	else if (c <= 0x7FF)
	{
		if (MB_CUR_MAX >= 2)
			return (2);
	}
	else if (c <= 0xFFFF)
	{
		if (MB_CUR_MAX >= 3)
			return (3);
	}
	else if (c <= 0x10FFFF)
	{
		if (MB_CUR_MAX >= 4)
			return (4);
	}
	return (0);
}

static int	return_eror(t_env *e)
{
	e->nc = -1;
	return (-1);
}

static int	flag_uni_c_anex(t_env *e, char flag, wchar_t wc)
{
	int add;

	add = 0;
	if (flag == 'C' || e->have_l != 0)
	{
		if (wc < 0)
			return (return_eror(e));
		add = print_wchar(wc);
	}
	else
	{
		ft_putchar(wc);
		add++;
	}
	if (add == -1)
		return (return_eror(e));
	while (e->int_value + (add - 1) < -1)
		ft_putchar_nc_int(' ', &e->int_value, e);
	e->nc += add;
	return (0);
}

int			flag_uni_c(t_env *e, va_list ap, char flag)
{
	char	c;
	wchar_t	wc;

	if (e->zero != 0)
		c = '0';
	else
		c = ' ';
	wc = va_arg(ap, wchar_t);
	if ((wc > 0xD7FF && wc < 0xE000) ||
		(wc > 0x2FFFF && wc < 0xE0000) || (wc >= 0x10FFFE))
		return (return_eror(e));
	while (e->int_value > 1)
		ft_putchar_nc_sup_int(c, &e->int_value, e);
	return (flag_uni_c_anex(e, flag, wc));
}
