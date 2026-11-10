/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:48:24 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:19:39 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function searches the last occurrence of a specific character in a string*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	ch;
	const char		*last;

	ch = (unsigned char)c;
	last = NULL;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			last = s;
		}
		s++;
	}
	if (ch == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last);
}

/*
#include <stdio.h>

int main(void)
{
    char str[] = "banana";
    char c = 'a';
    char *p;

    p = ft_strrchr(str, c);

    if (p != NULL)
        printf("He encontrado '%c' en: %s\n", c, p);
    else
        printf("No he encontrado '%c'\n", c);

    return (0);
}
*/

/*
#include <stdio.h>

int main(void)
{
    char str[] = "banana";
    char c = 'a';
    char *ultima;

    ultima = ft_strrchr(str, c);

    if (ultima != NULL)
		printf("Indice: %ld\n", ultima - str);
    else
        printf("No he encontrado '%c'\n", c);

    return (0);
}
*/

/*
#include <stdio.h>

int main(void)
{
    char str[] = "banana";
    char *p;

    p = ft_strrchr(str, 'a');
    if (p != NULL) //comprobamos si el puntero el válido antes de imprimirlo
        printf("Buscar 'a': %s\n", p);
    else
        printf("Buscar 'a': (null)\n");

    p = ft_strrchr(str, 'n');
    if (p != NULL)
        printf("Buscar 'n': %s\n", p);
    else
        printf("Buscar 'n': (null)\n");

    p = ft_strrchr(str, 'z');
    if (p != NULL)
        printf("Buscar 'z': %s\n", p);
    else
        printf("Buscar 'z': (null)\n");

    p = ft_strrchr(str, '\0');
    if (p != NULL)
        printf("Buscar '\\0': %s\n", p);
    else
        printf("Buscar '\\0': (null)\n");

    return (0);
}
*/
