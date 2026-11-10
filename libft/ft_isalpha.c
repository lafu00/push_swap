/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:41:04 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:17:40 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if the character is alphabetic*/

#include "libft.h"

int	ft_isalpha(int i)
{
	if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("A: %d\n", ft_isalpha('A'));
	printf("7: %d\n", ft_isalpha('7'));
	printf("z: %d\n", ft_isalpha('z'));
	printf("@: %d\n", ft_isalpha('@'));
	printf(" : %d\n", ft_isalpha(' '));
	printf("-: %d\n", ft_isalpha('-'));
	return (0);
}
*/
