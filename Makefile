NAME		= push_swap
NAME_BONUS	= checker

CC			= cc
CFLAGS		= -Wall -Werror -Wextra
LIBFT_DIR	= libft
LIBFT		= $(LIBFT_DIR)/libft.a
INCLUDES	= -I. -I$(LIBFT_DIR)

SRC			= algo_complex.c bench_utils.c push.c swap.c \
			  algo_medium.c init_stack.c reverse.c utils_calc.c \
			  algo_simple.c main_flag_stack.c rotate.c utils_parse.c \
			  bench.c select_strat.c utils_valid.c


DIR_BONUS	= bonus
SRC_BONUS	= $(DIR_BONUS)/get_next_line_bonus.c \
			  $(DIR_BONUS)/get_next_line_utils_bonus.c \
			  $(DIR_BONUS)/init_checker_stack.c \
			  $(DIR_BONUS)/main_checker.c \
			  $(DIR_BONUS)/push_write.c \
			  $(DIR_BONUS)/reverse_write.c \
			  $(DIR_BONUS)/rotate_write.c \
			  $(DIR_BONUS)/swap_write.c \
			  $(DIR_BONUS)/utils_calc.c \
			  $(DIR_BONUS)/utils_checker.c \
			  $(DIR_BONUS)/utils_parse.c \
			  $(DIR_BONUS)/utils_valid.c

OBJ			= $(SRC:%.c=%.o)
OBJ_BONUS	= $(SRC_BONUS:%.c=%.o)

HEADER		= push_swap.h
HEADER_BONUS = $(DIR_BONUS)/push_swap.h

all: $(NAME)

bonus: $(NAME_BONUS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(NAME_BONUS): $(LIBFT) $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(LIBFT) -o $(NAME_BONUS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(NAME_BONUS)

re:	fclean all

.PHONY: all bonus clean fclean re