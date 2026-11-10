/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:48:13 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:18:31 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that searches a substring within another string,
but only in the first "len" characters*/

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] && little[j] && i + j < len && big[i
				+ j] == little[j])
			j++;
		if (!little[j])
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int main() 
{
    const char *big = "Había una vez un circo";
    const char *little = "circo";
    size_t len = 30;

    char *result = ft_strnstr(big, little, len);
    if (result) 
    {
        printf("Subcadena encontrada: %s\n", result); // Imprime "circo"
    } else 
    {
        printf("Subcadena no encontrada\n");
    }

    return 0;
}
*/
