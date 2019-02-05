/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:38:57 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/26 11:15:16 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoinc(char c, char *s)
{
	unsigned int	u_j;
	unsigned int	u_size;
	char			*dest;

	u_j = -1;
	if (s == NULL)
		return (NULL);
	u_size = 1 + ft_strlen(s);
	dest = (char*)malloc(sizeof(*dest) * (u_size + 1));
	if (dest == NULL)
		return (NULL);
	dest[0] = c;
	while (s[++u_j] != '\0')
		dest[u_j + 1] = s[u_j];
	dest[1 + u_j] = '\0';
	return (dest);
}
