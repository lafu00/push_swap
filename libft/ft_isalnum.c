/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:40:45 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:16:43 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if a character is alphanumeric*/

#include "libft.h"

int	ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z')
		|| (i >= 'a' && i <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("A: %d\n", ft_isalnum('A'));
	printf("7: %d\n", ft_isalnum('7'));
	printf("z: %d\n", ft_isalnum('z'));
	printf("@: %d\n", ft_isalnum('@'));
	printf(" : %d\n", ft_isalnum(' '));
	printf("-: %d\n", ft_isalnum('-'));
	return (0);
}
*/
