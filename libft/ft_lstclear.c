/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:32:58 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:29:21 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		del(current->content);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
/* otra forma de hacerlo:

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *cajatemporal;

    cajatemporal = (*lst)->next;
    while (*lst != NULL)
    {
        del((*lst)->content);
        free(*lst);
        *lst = cajatemporal;
        if (cajatemporal != NULL)
            cajatemporal = cajatemporal->next;
    }
    *lst = NULL;
}
*/

/* otra forma de hacerlo (Carmen):

void ft_lstclear(t_list **lst, void (*del)(void*))
{
    t_list *cajatemporal;

    cajatemporal = (*lst)->next;
    while (*lst != NULL)
    {
       ft_lstdelone(*lst, del);
        *lst = cajatemporal;
        if (cajatemporal != NULL)
            cajatemporal = cajatemporal->next;
    }
    *lst = NULL;
}
*/

/* 
#include <stdio.h>
#include <stdlib.h>

static void del(void *ptr)
{
    free(ptr);
}

int main(void)
{
    t_list *head = NULL;
    t_list *n1 = ft_lstnew(ft_strdup("A"));
    t_list *n2 = ft_lstnew(ft_strdup("B"));

    ft_lstadd_back(&head, n1);
    ft_lstadd_back(&head, n2);

    printf("Antes de limpiar: %p\n", (void *)head);
    ft_lstclear(&head, del);
    printf("Después de limpiar: %p\n", (void *)head);
    return (0);
}
*/
