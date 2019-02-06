/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 07:49:41 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/14 07:49:46 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*u_str;
	size_t			u_index;

	u_str = (unsigned char *)s;
	u_index = 0;
	while (u_index < n)
	{
		if (u_str[u_index] == (unsigned char)c)
			return ((u_str + u_index));
		u_index++;
	}
	return (NULL);
}
