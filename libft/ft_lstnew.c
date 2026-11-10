/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lerodrig <lerodrig@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 13:25:45 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/09 12:48:24 by lerodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function that returns a pointer to a node (t_list*) */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}

/*
#include <stdio.h>

int main()
{
    char *str = "Hola mundo!";
    t_list *node = ft_lstnew(str);

    if (node)
    {
        printf("Node content: %s\n", (char *)node->content);
        printf("Next node: %p\n", (void *)node->next);
        free(node);
    }
    else
    {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
*/

/*

#include <stdio.h>

int main (void)
{
    t_list *nodo;
    nodo = ft_lstnew("Hola mundo!");
    printf("nodo: %p\n", nodo);
    printf("este es el contenido del nodo: %s\n", (char *)nodo->content);
    return (0);
}

*/
