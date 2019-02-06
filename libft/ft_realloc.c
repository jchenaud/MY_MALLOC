/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 07:26:15 by jchenaud          #+#    #+#             */
/*   Updated: 2017/01/23 12:36:40 by jeahoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_realloc(void *ptr, size_t size)
{
	void	*ret;

	if (ptr == NULL)
		return (NULL);
	if (size == 0)
		return (ptr);
	ret = malloc(sizeof(ptr) * (ft_strlen((char*)ptr) + size));
	ft_bzero(ret, ft_strlen((char*)ptr) + size);
	ret = ft_memcpy(ret, ptr, ft_strlen((char*)ptr));
	if (ret == NULL)
		return (ptr);
	free(ptr);
	return (ret);
}
