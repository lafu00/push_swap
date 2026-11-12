/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rehlich <rehlich@student.42malaga.com >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/12 11:51:49 by rehlich           #+#    #+#             */
/*   Updated: 2026/11/12 13:04:43 by rehlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **ori, t_node **dest)
{
	t_node	*temp;

	if (!ori || !*ori)
		temp = *ori;
	*ori = temp->next;
	if (*ori)
		(*ori)->prev = NULL;
	temp->prev = NULL;
	if (!*dest)
	{
	}
}
