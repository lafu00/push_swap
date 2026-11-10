/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:42:01 by lerodrig          #+#    #+#             */
/*   Updated: 2026/09/23 12:33:05 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Check if the character is a printable character*/

#include "libft.h"

int	ft_isprint(int i)
{
	if ((i >= 32 && i <= 126))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main(void)
{
	printf("32: %d\n", ft_isprint(32));
	printf("126: %d\n", ft_isprint(126));
	printf("-1: %d\n", ft_isprint(-1));
	printf("127: %d\n", ft_isprint(127));
	printf("128: %d\n", ft_isprint(128));
	return (0);
}
*/