/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:47:12 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:17:15 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that concatenates a string of characters to the end of another
and appends the null character*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)

{
	size_t	dst_len;
	size_t	src_len;
	size_t	j;

	dst_len = 0;
	src_len = 0;
	j = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
	{
		dst_len++;
	}
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (dst_len < size)
	{
		while (src[j] != '\0' && (dst_len + j) < (size - 1))
		{
			dst[dst_len + j] = src[j];
			j++;
		}
		dst[dst_len + j] = '\0';
	}
	return (dst_len + src_len);
}

/*
#include <stdio.h>

int	main(void)
{
    char	dst[20] = "Leticia";
    char	src[] = " Rodriguez";
    size_t	resultado;

    resultado = ft_strlcat(dst, src, sizeof(dst));

    printf("Resultado: %s\n", dst);
    printf("Longitud total: %zu\n", resultado);
    return (0);
}
*/

/*
#include <stdio.h>

	int main(void)
{
	char dst[18] = "Leticia";
	char src[] = " Rodriguez";
	char combinado[18] = "Leticia";
	size_t concatenacion;
	
	concatenacion = ft_strlcat(combinado, src, sizeof(combinado));
	printf("La cadena destino es : %s\n", dst);
	printf("La cadena a concatenar es : %s\n", src);
	printf("La cadena combinada es : %s\n", combinado);
	printf("El tamaño total de la cadena combinada es : %zu\n", concatenacion);
	return (0);
}
*/
