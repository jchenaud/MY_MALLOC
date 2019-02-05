/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 23:34:43 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 13:55:12 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_inc_intflag(int nb)
{
	int neg;
	int c;
	int n;

	neg = 0;
	c = 1;
	n = 0;
	if (nb < 0 && nb != -2147483648)
	{
		nb *= -1;
		neg = 1;
	}
	else if (nb == -2147483648)
		return (11);
	if (n < 1000000000)
	{
		while (c <= nb)
		{
			c *= 10;
			n++;
		}
		return (n + neg);
	}
	return (11);
}

int	int_flag_find(const char *str, unsigned int i)
{
	char	*int_flag;
	int		f;

	f = 0;
	int_flag = "1234567890-";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f])
		return (1);
	return (0);
}

int	int_flag_find_without_zero(const char *str, unsigned int i)
{
	char	*int_flag;
	int		f;

	f = 0;
	int_flag = "123456789";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f])
		return (1);
	return (0);
}

int	have_modi_flag(char c)
{
	int		i;
	char	*modi_flag;

	i = 0;
	modi_flag = " #.lhj+-0z";
	while (modi_flag[i] && c != modi_flag[i])
		i++;
	if (modi_flag[i] && c == modi_flag[i])
		return (1);
	return (0);
}

int	ft_int_flag_return_value(const char *str, unsigned int i, t_env *e)
{
	char	*int_flag;
	int		nb;
	int		f;

	f = 0;
	int_flag = "1234567890-";
	while (str[i + 1] != int_flag[f] && int_flag[f])
		f++;
	if (str[i + 1] == int_flag[f] && int_flag[f] && int_flag[f] != '.')
	{
		nb = ft_atoi(&str[i + 1]);
		if (nb < 0)
			i++;
		if (str[i + 1] == '0')
			e->zero++;
		return (nb);
	}
	return (0);
}
