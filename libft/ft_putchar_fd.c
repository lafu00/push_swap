/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:18 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:33:42 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that writes a character to a file or to standard output*/

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdio.h>

int main(void)
{
    ft_putchar_fd('K', 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
*/