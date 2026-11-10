/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:47:05 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:42:44 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that takes two strings and returns a new string 
that is the concatenation of both*/

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		total_len;
	int		i;
	int		j;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	result = (char *)malloc((total_len + 1) * sizeof(char));
	if (!result)
		return (0);
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = ft_strjoin("Leticia", " Rodriguez");

    printf("%s\n", s);
    free(s);
    return (0);
}
*/