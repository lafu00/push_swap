/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:44:42 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 13:40:41 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Funtion that copies n bytes from one memory location (src) to another (dest)*/

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>

int main(void)
{
    char dst[20] = "xxxxxxxxxx";
    char src[] = "Hola Pepe";

    printf("Antes: %s\n", dst);
    ft_memcpy(dst, src, 6);
    printf("Después: %s\n", dst);
    return (0);
}
*/
