/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:47:22 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:43:31 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that copies one string of characters (src)
to another (dst) and end with a null character*/

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size > 0)
	{
		i = 0;
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}
/* 
#include <stdio.h>

int main(void)
{
    char dst[20];
    char src[] = "abcdef";

    printf("ret = %zu\n", ft_strlcpy(dst, src, sizeof(dst)));
    printf("dst = %s\n", dst);
    return (0);
}
*/