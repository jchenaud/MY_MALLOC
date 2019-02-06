/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 07:18:04 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/12 07:18:13 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char *s_1;
	unsigned char *s_2;

	s_1 = (unsigned char*)s1;
	s_2 = (unsigned char*)s2;
	while (len > 0 && *s_1 == *s_2)
	{
		s_1++;
		s_2++;
		len--;
	}
	if (len == 0)
		return (0);
	else
		return (*s_1 - *s_2);
}
