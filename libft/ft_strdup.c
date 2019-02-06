/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 16:38:54 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/08 16:55:50 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned int	size;
	unsigned int	i;
	char			*tab;

	i = 0;
	size = ft_strlen(s) + 1;
	tab = (char*)malloc(sizeof(*tab) * (size));
	if (tab == NULL)
		return (NULL);
	while (i < size)
	{
		tab[i] = s[i];
		i++;
	}
	return (tab);
}
