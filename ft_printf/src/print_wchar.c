/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:30:52 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 13:58:09 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	anex(wchar_t c)
{
	if (c <= 0xFFFF)
	{
		if (MB_CUR_MAX >= 3)
		{
			ft_putchar((c >> 12) + 0xE0);
			ft_putchar(((c >> 6) & 0x3F) + 0x80);
			ft_putchar((c & 0x3F) + 0x80);
			return (3);
		}
	}
	else if (c <= 0x10FFFF)
	{
		if (MB_CUR_MAX >= 4)
		{
			ft_putchar((c >> 18) + 0xF0);
			ft_putchar(((c >> 12) & 0x3F) + 0x80);
			ft_putchar(((c >> 6) & 0x3F) + 0x80);
			ft_putchar((c & 0x3F) + 0x80);
			return (4);
		}
		return (0);
	}
	return (-1);
}

int			print_wchar(wchar_t c)
{
	if (c <= 0x7F)
	{
		if (MB_CUR_MAX >= 1)
		{
			ft_putchar(c);
			return (1);
		}
	}
	else if (c <= 0x7FF)
	{
		if (MB_CUR_MAX >= 2)
		{
			ft_putchar((c >> 6) + 0xC0);
			ft_putchar((c & 0x3F) + 0x80);
			return (2);
		}
	}
	else
		return (anex(c));
	return (-1);
}
