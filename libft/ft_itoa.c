/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:43:44 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:03:07 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that converts an integer into a string.*/

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count = 1;
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	num;

	len = count_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		num = -(long)n;
	else
		num = n;
	if (n < 0)
		str[0] = '-';
	while (len-- > (n < 0))
	{
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
    char	*str;

    str = ft_itoa(-42);
    if (str == NULL)
        return (1);
    printf("%s\n", str);
    free(str);
    return (0);
}
*/