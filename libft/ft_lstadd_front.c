/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:47:26 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:28:22 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that adds a new node at the beginning of a linked list */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/* otra forma de hacerla

void ft_lstadd_front(t_list **lst, t_list *new)
{
    if (!lst || !new)
        return;
    new->next = *lst;
    *lst = new;
}
*/

/* 
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    t_list *head = NULL;
    t_list *n1 = ft_lstnew(ft_strdup("uno"));
    t_list *n2 = ft_lstnew(ft_strdup("dos"));

    ft_lstadd_front(&head, n1);
    ft_lstadd_front(&head, n2);

    while (head)
    {
        printf("%s\n", (char *)head->content);
        head = head->next;
    }
    return (0);
}
*/