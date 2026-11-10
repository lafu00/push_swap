/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:51 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:37:07 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that writes a string to a file or to standard output*/

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}
/* 
#include <stdio.h>

int main(void)
{
    ft_putstr_fd("Hola desde fd\n", 1);
    return (0);
}
*/