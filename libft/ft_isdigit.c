/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:41:36 by lerodrig          #+#    #+#             */
/*   Updated: 2026/09/23 12:31:08 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if the character is a digit from 0 to 9*/

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>

int main (void)
{
	printf("0: %d\n", ft_isdigit('0'));
	printf("9: %d\n", ft_isdigit('9'));
	printf("A: %d\n", ft_isdigit('A'));
	printf("a: %d\n", ft_isdigit('a'));
	return (0);
}
*/