/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 13:54:35 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 13:56:31 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	next_flag(const char *str, int i)
{
	char	*int_flag;
	int		f;
	int		k;

	k = 0;
	int_flag = "1234567890.-  ";
	while (str[i + k])
	{
		f = 0;
		while (str[i + k] != int_flag[f] && int_flag[f])
			f++;
		if (!(int_flag[f]))
			return (str[i + k]);
		k++;
	}
	return (0);
}
