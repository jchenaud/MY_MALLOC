ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

FILE = 	malloc.c \
		#mylst.c \
		#show_alloc_mem.c \
		#print_func.c \
		#free.c \
		#realloc.c \
		#ft_malloc.c \
		#test.c

SRC_PATH = src
INCLUDES = include

BRI  = $(FILE:.c=.o)#$(patsubst %.c, %.o, $(SRC))
BRICK = $(addprefix $(SRC_PATH)/,$(BRI))
SRC = $(addprefix $(SRC_PATH)/,$(FILE))
FLAG = -Wall -Wextra



all:$(NAME)
$(NAME): $(BRICK)

	cd libft && make re
	# cd ..
	# gcc  $(SRC)  -I include  -I libft libft/libft.a
	# ar rc $(NAME) $(BRICK)
	gcc  -shared -o $(NAME) $(FLAG) -I include  -I libft libft/libft.a  $(SRC)
	# ar rc $(NAME) $(BRICK)
	# ranlib libft_malloc_$(HOSTTYPE).so
	ln -fs $(NAME) libft_malloc.so

host:
	echo $(HOSTTYPE)

test_true:
	gcc -o test_true $(SRC) test_true.c  -I include  -I libft libft/libft.a

rm_true:
	@rm test_true

re_true:rm_true test_true

$(BRICK): $(SRC)
	@gcc  -o $@ -I include  -I libft -c $<

# %.o: %.c includes/ft_// printf.h Makefile
# 	gcc -Wall -Wextra -Werror -o $@ -c $< -I includes

# $(NAME): $(BRICK) $(SRC)
# 	ar rc $(NAME) $(BRICK)
# 	ranlib $(NAME)

# clean:
# 	# @/bin/rm -f $(BRICK)

fclean: clean
# 	# @/bin/rm -f $(NAME)

re: fclean all

# .PHONY: re all clean fclean