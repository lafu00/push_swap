/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/21 13:15:59 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 12:55:33 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function to zero out a block of memory */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
}
/*
#include <stdio.h>

int main(void)
{
	char s[] = "Leticia Rodriguez";
	printf("Antes de bzero: %s\n", s);
	ft_bzero(s, 2);
	printf("Despues de bzero: %s\n", s + 2);
	return (0);
}
*/

/*	
#include <stdio.h>

int main(void)
{
	char str[50] = "Hola caracola";
	ft_bzero(str, sizeof(str));
	printf("%s\n", str);
	return (0);
}
*/
