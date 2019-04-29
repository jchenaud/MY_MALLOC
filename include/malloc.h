/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 16:08:24 by jchenaud          #+#    #+#             */
/*   Updated: 2019/04/29 15:48:58 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>
# include <stdbool.h>
# include <sys/mman.h>
# include "libft.h"
# include <stdint.h>
# include <pthread.h>
# include "libft.h"
# define TINY_LS 64
# define SMALL_LS 1024
# define FAIL_ALLOC (void *) -1
# define ALLIGN 16
# define ERROR 1
# define LOCK  1

typedef struct	s_zone
{
	int			used;
	void		*next;
	void		*mem;
	size_t		size;
}				t_zone;

typedef struct	s_env
{
	t_zone		*tiny;
	t_zone		*small;
	t_zone		*large;
}				t_env;
t_env			g_e;

void			*alloc(size_t size);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			free(void *ptr);
void			show_alloc_mem();
void			show_alloc_mem_content();
t_zone			*find_p(void *ptr);
t_zone			*find_p_in_zone(void *ptr, t_zone *flst);
void			ft_puthexa(void *ptr);
void			unlock();
void			lock();
void			*malloc_l(size_t size);
void			*realloc_l(void *ptr, size_t size);
void			free_l(void *ptr);
void			*p_erno(int i);
void			*rea_undifined();
void			*find_not_use(t_zone **flst, size_t size);
void			add_one_page_zone(t_zone **flst, size_t size_alloc);
void			page_init(t_zone **flst, size_t size_alloc,
					size_t reapit, void *p);
#endif
