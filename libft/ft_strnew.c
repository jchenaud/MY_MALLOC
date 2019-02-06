/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:48:24 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/12 09:35:45 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;
	size_t	u_i;

	u_i = 0;
	dest = (char*)malloc(sizeof(*dest) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (u_i < size)
	{
		dest[u_i] = '\0';
		u_i++;
	}
	dest[u_i] = '\0';
	return (dest);
}
