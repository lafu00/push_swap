/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:47:41 by lerodrig          #+#    #+#             */
/*   Updated: 2026/09/24 11:51:12 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Returns the character string length*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
#include <stdio.h>

int main(void)
{
    char *test = "Hola"; //Puntero a string
    
    printf("Cadena: %s\n", test); //Imprime cadena = "Hola"
    printf("Longitud: %zu\n", ft_strlen(test)); //Imprime Longitud = 4
    
    return (0);
}
*/

/*
#include <stdio.h>

int main(void)
{
    char name[7] = "Leticia";        // [7] para incluir el \0
    printf("La longitud de '%s' es: %zu\n", name, ft_strlen(name));
    return 0;
}
//salida: La longitud de 'Leticia' es: 7
*/

/*
#include <stdio.h>

int main(void)
{
	const char str1[] = "Hola, mundo!";
	const char str2[] = "42 Málaga es genial";
	printf("La longitud de %s es: %zu\n", str1, ft_strlen(str1));
	printf("La longitud de %s es: %zu\n", str2, ft_strlen(str2));
	return (0);
}
*/
