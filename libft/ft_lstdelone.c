/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:31:18 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:29:48 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
/*
#include <stdio.h>
#include <stdlib.h>

static void del(void *ptr)
{
    free(ptr);
}

int main(void)
{
    t_list *node = ft_lstnew(ft_strdup("hola"));

    printf("Antes: %s\n", (char *)node->content);
    ft_lstdelone(node, del);
    printf("Después de lstdelone\n");
    return (0);
}
*/