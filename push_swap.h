/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/04 15:13:18 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/06 20:06:46 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
//# include "libft/libft.h"

char	**matrix(int argc, char **argv);
void	free_matrix(char **total);
int		extract_flags(char **total);
int		is_valid_number(char **matrix);
long	ft_atol(const char *str, int *error);
int		if_duplicates(int *array, int size);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t num, size_t size);
#endif
