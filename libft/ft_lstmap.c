/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leticiro <leticiro@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 15:26:16 by lerodrig          #+#    #+#             */
/*   Updated: 2026/10/14 00:32:00 by leticiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
/* otra forma de hacerlo:

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))

{
    t_list *new_list;
    t_list *new_node;

    if (!lst || !f)
        return (NULL);
    new_list = NULL;
    while (lst)
    {
        new_node = ft_lstnew(f(lst->content));
        if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        if (!new_list)
            new_list = new_node;
        else
            ft_lstadd_back(&new_list, new_node);
        lst = lst->next;
    }
    return (new_list);
}
*/

/*
#include <stdio.h>
#include <stdlib.h>

static void *dup_up(void *content)
{
    char *s = ft_strdup((char *)content);
    int i = 0;

    if (!s)
        return (NULL);
    while (s[i])
    {
        s[i] = s[i] + 1;
        i++;
    }
    return ((void *)s);
}

static void del(void *ptr)
{
    free(ptr);
}

int main(void)
{
    t_list *head = ft_lstnew(ft_strdup("ab"));
    t_list *n2 = ft_lstnew(ft_strdup("cd"));
    t_list *new_list;

    ft_lstadd_back(&head, n2);
    new_list = ft_lstmap(head, dup_up, del);
    while (new_list)
    {
        printf("%s\n", (char *)new_list->content);
        new_list = new_list->next;
    }
    ft_lstclear(&head, del);
    return (0);
}
*/