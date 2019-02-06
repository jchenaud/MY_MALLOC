/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 09:00:45 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/07 10:16:26 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	unsigned int i;
	unsigned int negative;
	unsigned int nbr;

	nbr = 0;
	i = 0;
	negative = 0;
	while ((str[i] == 32) || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negative = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr + (int)(str[i]) - 48;
		i++;
	}
	if (negative == 1)
		return (-nbr);
	return (nbr);
}
