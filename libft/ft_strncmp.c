/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:48:03 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/05 13:54:26 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that compares two strings
up to a specified number of characters (`n`)*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((i < n) && ((s1[i] != '\0') || (s2[i] != '\0')))
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*s1 = "Hola";
    char	*s2 = "Hola";
    int		resultado;

    resultado = ft_strncmp(s1, s2, 4);

    printf("Resultado: %d\n", resultado);
    return (0);
}
*/

/*
#include <stdio.h>

int main (void)
{
	int resultado;
	resultado = ft_strncmp("Hola", "Holi", 4);
	printf("Resultado: %d\n", resultado);
	return (0);
}
*/

/*
#include <stdio.h>

int	main(void)
{
	//Cadenas iguales
	const char *s1 = "Hola mundo";
	const char *s2 = "Hola mundo";
	size_t n = 5;
	printf("Resultado: %d\n", ft_strncmp(s1, s2, n));

	//Primera cadena menor que la segunda
	s1 = "Hola";
	s2 = "Holb";
	n = 4;
	printf("Resultado: %d\n", ft_strncmp(s1, s2, n));

	//Segunda cadena menor que la primera
	s1 = "Holb";
	s2 = "Hola";
	n = 4;
	printf("Resultado: %d\n", ft_strncmp(s1, s2, n));

	//Comparación limitada por n
	s1 = "Hola mundo";
	s2 = "Hola Marte";
	n = 4;
	printf("Resultado: %d\n", ft_strncmp(s1, s2, n));

	//Una cadena vacía
	s1 = "";
	s2 = "Hola";
	n = 4;
	printf("Resultado: %d\n", ft_strncmp(s1, s2, n));

	//Ambas cadenas vacías
	s1 = "";
	s2 = "";
	n = 4;
	printf("Resultado: %d\n", ft_strncmp(s1, s2, n));

	return (0);
}
*/
