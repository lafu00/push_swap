/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:46:43 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:39:50 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that creates a copy of a string */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*copy;

	len = ft_strlen(s);
	copy = (char *)malloc((len + 1) * sizeof(char));
	if (copy == NULL)
	{
		return (NULL);
	}
	ft_memcpy(copy, s, len + 1);
	return (copy);
}
/* otra forma de hacerla

char	*ft_strdup(const char *src)
{
    size_t	len;
    size_t	i;
    char	*tmp;

    len = 0;
    i = 0;
    while (src[len])
        len++;
    tmp = malloc(sizeof(char) * (len + 1));
    if (!tmp)
        return (NULL);
    while (src[i])
    {
        tmp[i] = src[i];
        i++;
    }
    tmp[i] = '\0';
    return (tmp);
}
*/

/* 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = ft_strdup("Libft");

    printf("%s\n", s);
    free(s);
    return (0);
}
*/