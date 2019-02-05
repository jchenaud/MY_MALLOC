/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 17:40:38 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 17:42:28 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_end(t_env *e)
{
	int nb_char;

	nb_char = e->nc;
	if (e->ito)
	{
		free(e->ito);
		e->ito = NULL;
	}
	return (nb_char);
}

void	if_bigin(t_env *e, const char *str)
{
	if (e->i != 0 || str[e->i] != '%')
		ft_putchar_nc(str[e->i], e);
	if (str[e->i] != '%')
		e->i++;
}

int		core_while(t_env *e, const char *str, va_list ap)
{
	while ((str[e->i] && str[e->i] != '%') || (e->i == 0))
	{
		if_bigin(e, str);
		while (str[e->i] && str[e->i] == '%')
		{
			if (str[e->i + 1])
			{
				if (ft_check_flag(str, 1, ap, e) == -1)
				{
					va_end(ap);
					return (e->ret = ft_end(e));
				}
			}
			else
			{
				va_end(ap);
				return (e->ret = e->nc);
			}
			e->i = e->i + 2;
		}
	}
	e->ret = -2;
	return (-2);
}

int		ft_printf(const char *str, ...)
{
	t_env	e;
	va_list	ap;

	e.ito = NULL;
	e.string = NULL;
	e.nc = 0;
	e.i = 0;
	if (!(str[0]))
		return (0);
	va_start(ap, str);
	if (core_while(&e, str, ap) != -2)
		return (e.ret);
	va_end(ap);
	return (ft_end(&e));
}
