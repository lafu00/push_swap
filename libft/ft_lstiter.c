/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:23:27 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:30:21 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function to iterate over a linked list and 
apply a function to each element */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/* 
#include "libft.h"
#include <stdio.h>

static void print_node(void *content)
{
    printf("%s\n", (char *)content);
}

int main(void)
{
    t_list *head = ft_lstnew("uno");
    t_list *n2 = ft_lstnew("dos");

    ft_lstadd_back(&head, n2);
    ft_lstiter(head, print_node);
    return (0);
}
*/