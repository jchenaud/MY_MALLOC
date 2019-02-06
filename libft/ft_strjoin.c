/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:45:18 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/12 11:22:49 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int			ft_strsize(char const *str)
{
	unsigned int	u_i;

	u_i = 0;
	while (str[u_i])
		u_i++;
	return (u_i);
}

char						*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	u_i;
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_i = 0;
	u_j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	u_size = ft_strsize(s1) + ft_strsize(s2);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	while (s1[u_i] != '\0')
	{
		dest[u_i] = s1[u_i];
		u_i++;
	}
	while (s2[u_j] != '\0')
	{
		dest[u_i + u_j] = s2[u_j];
		u_j++;
	}
	dest[u_i + u_j] = '\0';
	return (dest);
}
