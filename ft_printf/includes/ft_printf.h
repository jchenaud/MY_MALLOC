/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:00:28 by jchenaud          #+#    #+#             */
/*   Updated: 2018/06/26 11:41:17 by jchenaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <limits.h>
# include <wchar.h>
# include <stdlib.h>
# include "env_printf.h"

int			ft_printf(const char *str, ...);
char		*ft_itoa_base(unsigned int nbr, int base, char maj);
char		*ft_neg_itoa_base(int nbr, int base, char maj);
char		*ft_itoa_base_large(uintmax_t nbr, int base, char maj);
char		*ft_neg_litoa_base(intmax_t nbr, int base, char maj);
char		*ft_llitoa_base(long long unsigned int nbr, int base, char maj);
int			x_flag(const char *str, va_list ap, t_env *e);
int			x_point_zero(t_env *e);
void		x_sharp(t_env *e, const char *str);
void		int_flag(const char *str, t_env *e);
char		next_flag(const char *str, int i);
int			have_modi_flag(const char c);
char		*ft_strjoinc(char c, char *s);
char		*ft_strdup(const char *s);
void		flag_pc(t_env *e);
void		flag_s(t_env *e, va_list ap, char flag);
void		s_char_can_print(t_env *e, int *char_can_print_size);
void		s_char_can_print_end(t_env *e,
	int *char_can_print_size, int i, int k);
void		flag_c(t_env *e, va_list ap);
void		flag_o(va_list ap, t_env *e, char flag);
void		flag_d(va_list ap, t_env *e);
void		flag_d_pos(t_env *e, int *modi_size, int *mod_pres, char c);
void		flag_d_pos_end(t_env *e, int *modi_size, int *mod_pres);
void		flag_d_neg(t_env *e, int *modi_size, int *mod_pres, char c);
void		flag_d_neg_end(t_env *e, int *modi_size, int *mod_pres, char c);
void		flag_u(va_list ap, t_env *e, char u);
void		flag_p(va_list ap, t_env *e);
int			ft_check_flag(const char *str,
	unsigned int init, va_list ap, t_env *e);
void		ft_modif_flag(const char *str, t_env *e);
int			int_flag_find(const char *str, unsigned int i);
int			int_flag_find_without_zero(const char *str, unsigned int i);
int			ft_int_flag_return_value(const char *str, unsigned int i, t_env *e);
int			ft_inc_intflag(int nb);
int			flag_uni_c(t_env *e, va_list ap, char flag);
int			ft_atoi(const char *str);
size_t		ft_strlen(const char *s);
void		ft_putchar(char c);
void		ft_uputchar(wchar_t c);
int			hexa_size(const char *str);
void		ft_putchar_nc(char c, t_env *e);
void		ft_putchar_nc_int(char c, int *i, t_env *e);
void		ft_putchar_nc_sup_int(char c, int *i, t_env *e);
void		ft_putchar_nc_pres_int(char c, int *i, t_env *e);
void		ft_putchar_nc_int_sint(char c, int *i, int *s, t_env *e);
int			size_wchar(wchar_t c);
int			print_wchar(wchar_t c);
size_t		ft_strlen_wchar(const wchar_t *s);
void		take_value_d(va_list ap, t_env *e);
void		take_value_o(va_list ap, t_env *e, char flag);
void		take_value_x_min(va_list ap, t_env *e);
void		take_value_x_maj(va_list ap, t_env *e);
void		take_value_u(va_list ap, t_env *e, char flag);
int			difzero(char *n, int s);
void		ft_putstr(char const *s);

#endif
