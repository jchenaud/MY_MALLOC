/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 14:38:33 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/24 14:39:20 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

void	lock(void)
{
	if (LOCK == 1)
		pthread_mutex_lock(&g_mutex);
}

void	unlock(void)
{
	if (LOCK == 1)
		pthread_mutex_unlock(&g_mutex);
}
