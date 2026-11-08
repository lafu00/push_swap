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
# include "libft/libft.h"

char	**matrix(int argc, char **argv);
void	free_matrix(char **total);
int		extract_flags(char **total);
int		is_valid_number(char **matrix);
long	ft_atol(const char *str, int *error);
int		if_duplicates(int *array, int size);
double	calc_disorder(int *temp, int size);
int		*calc_index(int *temp, int size);

#endif
