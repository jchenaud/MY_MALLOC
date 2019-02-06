 NAME = malloc

FILE = 	ft_malloc.c mylst.c test.c  show_alloc_mem.c print_func.c\

SRC_PATH = src
INCLUDES = include
SRC = $(addprefix $(SRC_PATH)/,$(FILE))

BRICK = $(patsubst %.c, %.o, $(SRC))

all:$(NAME)
$(NAME):

	# cd ft_printf && make re
	# cd ..
	gcc  $(SRC)  -I include  -I libft libft/libft.a

# %.o: %.c includes/ft_printf.h Makefile
# 	gcc -Wall -Wextra -Werror -o $@ -c $< -I includes

# $(NAME): $(BRICK) $(SRC)
# 	ar rc $(NAME) $(BRICK)
# 	ranlib $(NAME)

# clean:
# 	# @/bin/rm -f $(BRICK)

# fclean: clean
# 	# @/bin/rm -f $(NAME)

# re: fclean all

# .PHONY: re all clean fclean