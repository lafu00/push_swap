/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:41:18 by lerodrig          #+#    #+#             */
/*   Updated: 2026/09/23 12:28:40 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Checks if the character belongs to the ASCII table*/

#include "libft.h"

int	ft_isascii(int i)
{
	if ((i >= 0 && i <= 127))
		return (1);
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("0: %d\n", ft_isascii(0));
	printf("127: %d\n", ft_isascii(127));
	printf("-1: %d\n", ft_isascii(-1));
	printf("128: %d\n", ft_isascii(128));
	return (0);
}
*/	
