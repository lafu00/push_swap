/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:57:36 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:32:50 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

/* otra forma de hacerlo

unsigned int ft_lstsize(t_list *lst)
{
    unsigned int count = 0;

    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return count;
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list *head = NULL;
    t_list *n1 = ft_lstnew(ft_strdup("A"));
    t_list *n2 = ft_lstnew(ft_strdup("B"));

    ft_lstadd_back(&head, n1);
    ft_lstadd_back(&head, n2);

    printf("Tamaño: %u\n", ft_lstsize(head));
    return (0);
}
*/