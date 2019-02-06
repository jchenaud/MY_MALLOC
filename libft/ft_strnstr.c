/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:12:01 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/10 07:23:29 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		i;
	size_t		j;
	int			size;

	i = 0;
	j = 0;
	size = 0;
	while (s2[size])
		size++;
	if (size == 0)
		return ((char *)s1);
	while (s1[i])
	{
		while (s2[j] == s1[i + j] && s2[j])
			j++;
		if (s2[j] == '\0' && i + j <= len)
			return ((char *)s1 + i);
		j = 0;
		i++;
	}
	return (NULL);
}
