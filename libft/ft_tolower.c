/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:49:00 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:20:07 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Converts the character to it's corresponding lowercase letter*/

#include "libft.h"

int	ft_tolower(int i)
{
	if (i >= 'A' && i <= 'Z')
		return (i +32);
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
	printf("A: %c\n", ft_tolower('A'));
	printf("Z: %c\n", ft_tolower('Z'));
	printf("a: %c\n", ft_tolower('a'));
	printf("z: %c\n", ft_tolower('z'));
	return (0);
}
*/
