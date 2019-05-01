ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

NAME = libft_malloc_$(HOSTTYPE).so

FLAGS = -Wall -Wextra -Werror -g

LIBFT = libft

HEADERS		= -Iinclude/ -I$(LIBFT)/
C_DIR		= src
H_DIR		= include
O_DIR 		= .OBJS
# TEST_DIR	= test

# TEST_FILES 	= $(shell find $(TEST_DIR) -type f -follow)

C_FILES 	= $(shell find $(C_DIR) -type f -follow)
H_FILES 	= $(shell find $(H_DIR) -type f -follow)
O_FILES = $(C_FILES:%.c=$(O_DIR)/%.o)

.PHONY: all, clean, fclean, re, norme, m_test

all : $(NAME)

$(NAME) : $(O_DIR)  $(O_FILES)
	@echo "/////comp libft///\n"
	cd libft/ && make
	@echo "/////comp my_malloc///\n"
	gcc $(FLAGS) -shared -o $@ $(O_FILES) -L$(LIBFT) -lft
	@echo "/////make  symbolic linck///\n"

	ln -sf $(NAME) libft_malloc.so

$(O_DIR)/%.o: %.c
	gcc -o $@ -c $< $(HEADERS)

$(O_DIR):
	mkdir -p $(O_DIR)/$(C_DIR)

clean:
	rm -rf ./test_true
	cd libft/ && make clean	
	rm -rf $(O_DIR)


fclean: clean
	cd libft/ && make fclean	
	rm -rf $(NAME)

re: fclean all


norminette:
	norminette $(C_FILES) $(H_FILES)

# m_test:
# 	@RM ./test_true || true
# 	@gcc -o test_true $(C_FILES) test_true.c  -I include  -I libft libft/libft.a
# 	@gcc -o test6 $(C_FILES) test6.c  -I include  -I libft libft/libft.a
# 	@gcc -o test7 $(C_FILES) test7.c  -I include  -I libft libft/libft.a




