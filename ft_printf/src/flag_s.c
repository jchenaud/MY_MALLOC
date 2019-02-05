/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 12:48:59 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 10:44:39 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	juste_write(t_env *e, char flag)
{
	int i;
	int add;

	if (flag == 's')
	{
		write(1, e->string, e->size);
		e->nc += e->size;
	}
	else
	{
		i = 0;
		while (i < e->size)
		{
			add = 0;
			if (e->have_point == 1)
			{
				e->presition -= size_wchar(e->string_wc[i]);
				if (e->presition < 0)
					return ;
			}
			add = print_wchar(e->string_wc[i]);
			i++;
			e->nc += add;
		}
	}
}

static void	flag_s_min(t_env *e, va_list ap, char flag, char c)
{
	e->string = va_arg(ap, char*);
	if (!e->string)
		e->string = "(null)";
	e->size = ft_strlen(e->string);
	if (e->have_point == 1)
	{
		if (e->presition < e->size)
			e->size = e->presition;
	}
	if (e->int_value <= e->size && e->int_value >= 0)
	{
		juste_write(e, flag);
		return ;
	}
	if (e->int_value > e->size || e->int_value < 0)
	{
		while (e->int_value - e->size > 0)
			ft_putchar_nc_sup_int(c, &e->int_value, e);
		juste_write(e, flag);
		while (e->int_value + e->size < 0)
			ft_putchar_nc_int(' ', &e->int_value, e);
	}
}

static void	s_print(t_env *e, int char_can_print_size, char c, char flag)
{
	while (e->int_value - char_can_print_size > 0)
		ft_putchar_nc_sup_int(c, &e->int_value, e);
	e->presition = e->tmp_p;
	e->size = e->tmp_s;
	juste_write(e, flag);
	while (e->int_value + char_can_print_size < 0)
		ft_putchar_nc_int(' ', &e->int_value, e);
}

static void	flag_s_maj(t_env *e, va_list ap, char flag, char c)
{
	int char_can_print_size;

	char_can_print_size = 0;
	e->string_wc = va_arg(ap, wchar_t *);
	if (!e->string_wc)
		e->string_wc = L"(null)";
	e->size = ft_strlen_wchar(e->string_wc);
	if (e->have_point == 1)
	{
		if (e->presition < e->size)
			e->size = e->presition;
	}
	if (e->int_value <= e->size && e->int_value >= 0)
	{
		juste_write(e, flag);
		return ;
	}
	if (e->int_value > e->size || e->int_value < 0)
	{
		s_char_can_print(e, &char_can_print_size);
		s_print(e, char_can_print_size, c, flag);
	}
}

void		flag_s(t_env *e, va_list ap, char flag)
{
	char c;

	if (e->zero != 0 && e->have_l == 0)
		c = '0';
	else
		c = ' ';
	if (flag == 's' && e->have_l != 0)
		flag = 'S';
	if (flag == 's')
		flag_s_min(e, ap, flag, c);
	else
		flag_s_maj(e, ap, flag, c);
}
