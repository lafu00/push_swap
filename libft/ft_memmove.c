/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:44:56 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/13 22:20:55 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that copies a memory block from one location to another*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	len;

	len = 0;
	if (!dst && !src)
		return (NULL);
	if (src < dst)
	{
		len = n;
		while (len > 0)
		{
			len--;
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		len = 0;
		while (len < n)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
			len++;
		}
	}
	return (dst);
}
/*
#include <stdio.h>

int main(void)
{
    char s[] = "abcdef";

    printf("Antes: %s\n", s);
    ft_memmove(s + 2, s, 4);
    printf("Después: %s\n", s);
    return (0);
}
*/