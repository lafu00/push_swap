/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:31 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:35:31 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that writes a string and a new line,
to a file or to standard output.*/

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
	write(fd, "\n", 1);
}
/* 
#include <stdio.h>

int main(void)
{
    ft_putendl_fd("Hola desde fd", 1);
    return (0);
}
*/