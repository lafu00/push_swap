/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:42 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:37:10 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that prints an integer to a file descriptor*/

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		num = (unsigned int)(n * -1);
	}
	else
		num = (unsigned int)n;
	if (num >= 10)
		ft_putnbr_fd(num / 10, fd);
	ft_putchar_fd((char)(num % 10 + 48), fd);
}
/* 
#include <stdio.h>

int main(void)
{
    ft_putnbr_fd(-12345, 1);
    ft_putchar_fd('\n', 1);
    return (0);
}
*/