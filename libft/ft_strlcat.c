/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:04:09 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/09 11:04:42 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_dst;
	size_t	index;
	size_t	size_src;

	size_dst = 0;
	index = 0;
	size_src = 0;
	while (src[size_src])
		size_src++;
	while (dst[size_dst] && size_dst < size)
		size_dst++;
	index = size_dst;
	while (src[size_dst - index] && size_dst < size - 1)
	{
		dst[size_dst] = src[size_dst - index];
		size_dst++;
	}
	if (index < size)
		dst[size_dst] = '\0';
	return (size_src + index);
}
