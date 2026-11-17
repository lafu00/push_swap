/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putstr_fd.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: rehlich <rehlich@student.42malaga.com>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/04 17:18:13 by rehlich          #+#    #+#              */
/*   Updated: 2026/11/16 20:40:51 by rehlich         ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/*Ft print s to a specific output channel.*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	size;

	size = 0;
	if (!s)
		return ;
	while (s[size] != '\0')
		size++;
	write(fd, s, size);
	return ;
}
