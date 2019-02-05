/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:06:38 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 17:47:33 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(long long unsigned int nbr, int base)
{
	int i;

	i = 1;
	while (nbr / base > 0)
	{
		nbr = nbr / base;
		i++;
	}
	return (i);
}

static void	ft_recursive_min(char *str,
	long long unsigned int nbr, int base, int i)
{
	char *t;

	t = "0123456789abcdef";
	if (i > 0)
	{
		ft_recursive_min(str, nbr / base, base, i - 1);
		str[i - 1] = t[nbr % base];
	}
}

static void	ft_recursive_maj(char *str,
	long long unsigned int nbr, int base, int i)
{
	char *t;

	t = "0123456789ABCDEF";
	if (i > 0)
	{
		ft_recursive_maj(str, nbr / base, base, i - 1);
		str[i - 1] = t[nbr % base];
	}
}

char		*ft_llitoa_base(long long unsigned int nbr, int base, char maj)
{
	int		nb;
	char	*str;

	nb = ft_size(nbr, base);
	str = (char *)malloc(sizeof(char) * (nb + 1));
	if (str == NULL)
		return (NULL);
	if (maj == 0)
		ft_recursive_min(str, nbr, base, nb);
	else
		ft_recursive_maj(str, nbr, base, nb);
	str[nb] = '\0';
	return (str);
}
