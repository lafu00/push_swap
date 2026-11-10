/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:44:29 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:25:53 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that compares two memory blocks*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	while (n--)
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
	}
	return (0);
}
/* 
#include <stdio.h>

int main(void)
{
    printf("cmp1 = %d\n", ft_memcmp("abcd", "abce", 4));
    printf("cmp2 = %d\n", ft_memcmp("abcd", "abcd", 4));
    return (0);
}
*/