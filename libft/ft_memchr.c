/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:43:57 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:25:12 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that finds the first occurrence of a specific byte
in a memory block*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)

{
	unsigned char	*ptr;
	unsigned char	character;
	size_t			i;

	ptr = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (*ptr == character)
			return ((void *)ptr);
		ptr++;
		i++;
	}
	return (NULL);
}

/* 
#include <stdio.h>

int main(void)
{
    char s[] = "abcdef";
    char *p;

    p = ft_memchr(s, 'd', 6);
    if (p)
        printf("Encontrado: %c\n", *p);
    else
        printf("No encontrado\n");
    return (0);
}
*/