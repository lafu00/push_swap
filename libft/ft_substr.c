/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:48:52 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:45:31 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that extracts a substring from a given string*/

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup (""));
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (s + start), (len + 1));
	return (substr);
}
/* 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = ft_substr("abcdef", 2, 3);

    printf("%s\n", s);
    free(s);
    return (0);
}
*/