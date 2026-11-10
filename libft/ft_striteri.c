/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 11:46:51 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:41:15 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Function that applies a function f to each character of the string s
and does not return a value*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/* 

#include <stdio.h>

static void upper(unsigned int i, char *c)
{
    (void)i;
    if (*c >= 'a' && *c <= 'z')
        *c = *c - 32;
}

int main(void)
{
    char s[] = "hello";

    ft_striteri(s, upper);
    printf("%s\n", s);
    return (0);
}
*/