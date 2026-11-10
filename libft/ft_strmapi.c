/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:47:53 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:44:02 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that applies a function f to each character in the string s
to create a new string*/

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/* 
#include <stdio.h>
#include <stdlib.h>

static char to_upper(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int main(void)
{
    char *s = ft_strmapi("hello", to_upper);

    printf("%s\n", s);
    free(s);
    return (0);
}
*/