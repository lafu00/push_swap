NAME	=	checker

CFLAGS	=	-Wall -Werror -Wextra
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

SRC	=	get_next_line_bonus.c	main_checker.c	rotate_write.c	utils_checker.c\
		get_next_line_utils_bonus.c	push_write.c	swap_write.c	utils_parse.c\
		init_checker_stack.c	reverse_write.c	utils_calc.c	utils_valid.c

OBJ	=	$(SRC:%.c=%.o)

HEADER	=	checker

all:	$(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	cc $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o	:	%.c	$(HEADER)
	cc $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
