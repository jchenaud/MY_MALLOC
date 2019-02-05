/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/24 14:37:48 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/25 14:06:44 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	take_value_d(va_list ap, t_env *e)
{
	if (e->ito != NULL)
	{
		free(e->ito);
		e->ito = NULL;
	}
	if (e->have_l >= 2)
		e->ito = ft_neg_litoa_base(
				(long long int)(va_arg(ap, long long int)), 10, 0);
	else if (e->have_l == 1)
		e->ito = ft_neg_litoa_base((long int)(va_arg(ap, long int)), 10, 0);
	else if (e->have_j != 0)
		e->ito = ft_neg_litoa_base((intmax_t)(va_arg(ap, intmax_t)), 10, 0);
	else if (e->have_z != 0)
		e->ito = ft_neg_litoa_base((size_t)(va_arg(ap, size_t)), 10, 0);
	else if (e->have_h == 1)
		e->ito = ft_neg_litoa_base((short int)(va_arg(ap, int)), 10, 0);
	else if (e->have_h > 1)
		e->ito = ft_neg_litoa_base((signed char)(va_arg(ap, int)), 10, 0);
	else
		e->ito = ft_neg_litoa_base((int)(va_arg(ap, int)), 10, 0);
	e->size = ft_strlen(e->ito);
	if (e->ito[0] == '-')
		e->ito_neg = 1;
	else
		e->ito_neg = 0;
}

void	take_value_o(va_list ap, t_env *e, char flag)
{
	if (flag == 'O')
		e->ito = ft_llitoa_base((unsigned long long int)
			(va_arg(ap, unsigned long long int)), 8, 0);
	else if (e->have_l >= 2)
		e->ito = ft_llitoa_base((unsigned long long int)
			(va_arg(ap, unsigned long long int)), 8, 0);
	else if (e->have_l == 1)
		e->ito = ft_llitoa_base((unsigned long int)
			(va_arg(ap, unsigned long int)), 8, 0);
	else if (e->have_j != 0)
		e->ito = ft_llitoa_base((uintmax_t)(va_arg(ap, uintmax_t)), 8, 0);
	else if (e->have_z != 0)
		e->ito = ft_llitoa_base((ssize_t)(va_arg(ap, ssize_t)), 8, 0);
	else if (e->have_h == 1)
		e->ito = ft_llitoa_base((unsigned short int)(va_arg(ap, int)), 8, 0);
	else if (e->have_h > 1)
		e->ito = ft_llitoa_base((unsigned char)
			(va_arg(ap, unsigned int)), 8, 0);
	else
		e->ito = ft_llitoa_base((unsigned int)(va_arg(ap, unsigned int)), 8, 0);
	e->size = ft_strlen(e->ito);
}

void	take_value_x_min(va_list ap, t_env *e)
{
	if (e->have_l >= 2)
		e->ito = ft_llitoa_base((unsigned long long int)
			(va_arg(ap, unsigned long long int)), 16, 0);
	else if (e->have_l == 1)
		e->ito = ft_llitoa_base((unsigned long int)
			(va_arg(ap, unsigned long int)), 16, 0);
	else if (e->have_j != 0)
		e->ito = ft_llitoa_base((uintmax_t)(va_arg(ap, uintmax_t)), 16, 0);
	else if (e->have_z != 0)
		e->ito = ft_llitoa_base((ssize_t)(va_arg(ap, ssize_t)), 16, 0);
	else if (e->have_h == 1)
		e->ito = ft_llitoa_base((unsigned short int)(va_arg(ap, int)), 16, 0);
	else if (e->have_h > 1)
		e->ito = ft_llitoa_base((unsigned char)(va_arg(ap, int)), 16, 0);
	else
		e->ito = ft_llitoa_base((unsigned int)
			(va_arg(ap, unsigned int)), 16, 0);
	e->size = ft_strlen(e->ito);
}

void	take_value_x_maj(va_list ap, t_env *e)
{
	if (e->have_l >= 2)
		e->ito = ft_llitoa_base((unsigned long long int)
			(va_arg(ap, unsigned long long int)), 16, 1);
	else if (e->have_l == 1)
		e->ito = ft_llitoa_base((unsigned long int)
			(va_arg(ap, unsigned long int)), 16, 1);
	else if (e->have_j != 0)
		e->ito = ft_llitoa_base((uintmax_t)(va_arg(ap, uintmax_t)), 16, 1);
	else if (e->have_z != 0)
		e->ito = ft_llitoa_base((ssize_t)(va_arg(ap, ssize_t)), 16, 1);
	else if (e->have_h == 1)
		e->ito = ft_llitoa_base((unsigned short int)(va_arg(ap, int)), 16, 1);
	else if (e->have_h > 1)
		e->ito = ft_llitoa_base((unsigned char)(va_arg(ap, int)), 16, 1);
	else
		e->ito = ft_llitoa_base((unsigned int)
			(va_arg(ap, unsigned int)), 16, 1);
	e->size = ft_strlen(e->ito);
}

void	take_value_u(va_list ap, t_env *e, char flag)
{
	if (flag == 'U')
		e->have_l++;
	if (e->have_l >= 2)
		e->ito = ft_llitoa_base((unsigned long long int)
				(va_arg(ap, unsigned long long int)), 10, 0);
	else if (e->have_l == 1)
		e->ito = ft_llitoa_base((unsigned long int)
			(va_arg(ap, unsigned long int)), 10, 0);
	else if (e->have_j != 0)
		e->ito = ft_llitoa_base((uintmax_t)(va_arg(ap, uintmax_t)), 10, 0);
	else if (e->have_z != 0)
		e->ito = ft_llitoa_base((ssize_t)(va_arg(ap, ssize_t)), 10, 0);
	else if (e->have_h == 1)
		e->ito = ft_llitoa_base((unsigned short int)(va_arg(ap, int)), 10, 0);
	else if (e->have_h > 1)
		e->ito = ft_llitoa_base((unsigned char)(va_arg(ap, int)), 10, 0);
	else
		e->ito = ft_llitoa_base((unsigned int)
			(va_arg(ap, unsigned int)), 10, 0);
	e->size = ft_strlen(e->ito);
}
