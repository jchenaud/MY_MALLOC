/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 11:42:59 by jchenaud          #+#    #+#             */
/*   Updated: 2016/12/13 07:39:51 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *dl;

	if (alst)
	{
		dl = *alst;
		del(dl->content, dl->content_size);
		free(dl);
		*alst = dl->next;
		dl = NULL;
	}
}
