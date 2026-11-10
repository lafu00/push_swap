# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/22 11:49:56 by lerodrig          #+#    #+#              #
#    Updated: 2026/10/09 10:50:21 by lerodrig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable name
NAME = libft.a

# Compilator and flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Commands for cleaning and creating
RM = rm -f
AR = ar crs

# Source files and object files
SRC = ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_tolower.c \
ft_toupper.c \
ft_strlen.c \
ft_memset.c \
ft_bzero.c \
ft_memcpy.c \
ft_strchr.c \
ft_strrchr.c \
ft_strlcpy.c \
ft_strlcat.c \
ft_strncmp.c \
ft_memmove.c \
ft_memchr.c \
ft_memcmp.c \
ft_strnstr.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_strjoin.c \
ft_substr.c \
ft_strtrim.c \
ft_split.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \

OBJ = $(SRC:.c=.o)

# Rule for building the executable
$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for the default target
all: $(NAME)

# Rule for cleaning object files
clean:
	$(RM) $(OBJ)

# Rule for cleaning everything
fclean: clean
	$(RM) $(NAME)

# Rule for rebuilding everything
re: fclean all

.PHONY: all clean fclean re