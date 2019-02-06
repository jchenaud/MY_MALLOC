/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:07:27 by jchenaud          #+#    #+#             */
/*   Updated: 2016/11/12 11:28:24 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t u_i;

	if (!s1 || !s2)
		return (0);
	u_i = 0;
	while (s1[u_i] == s2[u_i] && s1[u_i] && u_i < n)
		u_i++;
	if (u_i >= n)
		u_i--;
	if (s1[u_i] != s2[u_i])
		return (0);
	return (1);
}
