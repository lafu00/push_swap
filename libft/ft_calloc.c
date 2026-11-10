/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:40:12 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 11:59:10 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that assign memory for a specific number of elements,
initializing all bytes to zero.*/

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	total_size;

	total_size = nmemb * size;
	if (nmemb != 0 && total_size / nmemb != size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
/*
#include <stdio.h>

int	main(void)
{
    int	*numbers;
    int	i;

    numbers = ft_calloc(3, sizeof(int));
    if (numbers == NULL)
        return (1);
    i = 0;
    while (i < 3)
    {
        printf("%d\n", numbers[i]);
        i++;
    }
    free(numbers);
    return (0);
}
*/