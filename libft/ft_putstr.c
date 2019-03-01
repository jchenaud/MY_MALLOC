/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 07:28:50 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/12 11:52:07 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char const *s)
{
	unsigned int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		i++;
    write(1,s,i);
}