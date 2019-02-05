# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchenaud <jchenaud@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 13:06:13 by jchenaud          #+#    #+#              #
#    Updated: 2018/06/26 13:07:56 by jchenaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FILE = 	ft_printf.c x_flag.c ft_strlen.c ft_putnbr.c ft_putstr.c  ft_strdup.c ft_putchar.c\
		ft_intflag.c ft_atoi.c ft_itoa_base_large.c  ll_itoa_base.c\
		ft_strjoin.c ft_nega_litoa_base.c flag_pc.c flag_s.c flag_o.c flag_d.c flag_d_anex.c flag_u.c\
		flag_p.c flag_uni_c.c easy_func.c take_value.c flag_s_size.c print_wchar.c next_flag.c ft_check_flag.c ft_modif_flag.c\
		func_util.c\

SRC_PATH = src
INCLUDES = includes
SRC = $(addprefix $(SRC_PATH)/,$(FILE))

BRICK = $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

%.o: %.c includes/ft_printf.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $< -I includes

$(NAME): $(BRICK) $(SRC)
	ar rc $(NAME) $(BRICK)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(BRICK)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: re all clean fclean
