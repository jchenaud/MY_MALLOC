/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 07:25:31 by jchenaud          #+#    #+#             */
/*   Updated: 2016/12/14 07:32:52 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*tmpres;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	tmp = f(lst);
	if ((res = ft_lstnew(tmp->content, tmp->content_size)))
	{
		tmpres = res;
		lst = lst->next;
		while (lst != NULL)
		{
			tmp = (*f)(lst);
			if (!(tmpres->next = ft_lstnew(tmp->content, tmp->content_size)))
				return (NULL);
			tmpres = tmpres->next;
			lst = lst->next;
		}
	}
	return (res);
}
