/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:45:07 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 12:30:52 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that fills a memory area with duplicate bytes*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int main(void)
{
    char s[] = "abcdef";

    printf("Antes: %s\n", s);
    ft_memset(s, '#', 3);
    printf("Después: %s\n", s);
    return (0);
}
*/

