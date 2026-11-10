/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:51:54 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:27:34 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that adds a new node at the end of a linked list */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ultimo_nodo;

	if (!lst || !new)
		return ;
	ultimo_nodo = ft_lstlast(*lst);
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ultimo_nodo->next = new;
}
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

    while (head)
    {
        printf("%s\n", (char *)head->content);
        head = head->next;
    }
    return (0);
}
*/