/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:46:30 by lerodrig          #+#    #+#             */
/*   Updated: 2026/09/24 13:32:38 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function searches the first occurrence of a specific character in a string*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;

	ch = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	str[] = "hola mundo";
	char	*result;

	result = ft_strchr(str, 'm');
	if (result)
		printf("Encontrado: %s\n", result);
	else
		printf("No encontrado\n");

	result = ft_strchr(str, 'z');
	if (result)
		printf("Encontrado: %s\n", result);
	else
		printf("No encontrado\n");

	result = ft_strchr(str, '\0');
	if (result)
		printf("Buscando '\\0': %s\n", result);
	else
		printf("No encontrado\n");

	return (0);
}
*/
/* Implementacion con índice:

char *ft_strchr(const char *s, int c)
{
    unsigned char ch = (unsigned char)c; 
    size_t i = 0; 

    while (s[i] != '\0') 
    {
        if (s[i] == ch) 
        {
            return (char *)&s[i]; 
        }
        i++; 
    }

    if (ch == '\0')
    {
        return (char *)&s[i];
    }

    return NULL;
} 
*/