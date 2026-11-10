/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:48:38 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:44:54 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that removes unwanted characters (defined in set)
from the start and end of a string (s1)*/

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + 1));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + 1);
	}
	return (str);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = ft_strtrim("   abcdef   ", " ");

    printf("[%s]\n", s);
    free(s);
    return (0);
}
*/