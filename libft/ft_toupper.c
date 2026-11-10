/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:49:26 by lerodrig          #+#    #+#             */
/*   Updated: 2026/09/23 12:37:34 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Converts the character to it's corresponding uppercase letter*/

#include "libft.h"

int	ft_toupper(int i)
{
	if (i >= 'a' && i <= 'z')
		return (i -32);
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
	printf("a: %c\n", ft_toupper('a'));
	printf("z: %c\n", ft_toupper('z'));
	printf("A: %c\n", ft_toupper('A'));
	printf("Z: %c\n", ft_toupper('Z'));
	return (0);
}
*/