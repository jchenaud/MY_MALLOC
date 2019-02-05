/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 11:17:05 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 22:00:44 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_nc(char c, t_env *e)
{
	ft_putchar(c);
	e->nc++;
}

void	ft_putchar_nc_int(char c, int *i, t_env *e)
{
	ft_putchar(c);
	e->nc++;
	(*i)++;
}

void	ft_putchar_nc_sup_int(char c, int *i, t_env *e)
{
	ft_putchar(c);
	e->nc++;
	(*i)--;
}

void	ft_putchar_nc_pres_int(char c, int *i, t_env *e)
{
	ft_putchar(c);
	e->nc++;
	(*i)++;
	e->presition--;
}

void	ft_putchar_nc_int_sint(char c, int *i, int *s, t_env *e)
{
	ft_putchar(c);
	e->nc++;
	(*i)++;
	(*s)--;
}
