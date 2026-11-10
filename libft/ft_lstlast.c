/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:18:34 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:31:16 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function to get the last element of a linked list */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list *head = NULL;
    t_list *n1 = ft_lstnew(ft_strdup("A"));
    t_list *n2 = ft_lstnew(ft_strdup("B"));
    t_list *last;

    ft_lstadd_back(&head, n1);
    ft_lstadd_back(&head, n2);

    last = ft_lstlast(head);
    printf("Último nodo: %s\n", (char *)last->content);
    return (0);
}
*/