/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 08:13:14 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/14 08:13:35 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *s_src;
	char *s_dst;

	s_src = (char*)src;
	s_dst = (char*)dst;
	if (s_src < s_dst)
	{
		s_src = s_src + len - 1;
		s_dst = s_dst + len - 1;
		while (len > 0)
		{
			*s_dst-- = *s_src--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*s_dst++ = *s_src++;
			len--;
		}
	}
	return (dst);
}
