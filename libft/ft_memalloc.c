/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:53:37 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/07 13:18:19 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;
	size_t	u_i;
	char	*str2;

	u_i = 0;
	str = (void *)malloc(sizeof(*str) * (size));
	if (str == NULL)
		return (NULL);
	str2 = (char *)str;
	while (u_i < size)
	{
		str2[u_i] = 0;
		u_i++;
	}
	return (str);
}
