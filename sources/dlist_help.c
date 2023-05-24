/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 13:09:05 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/24 13:09:27 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack_ptr *p)
{
	t_node	*node;

	node = p->a->start;
	while (node != p->a->end)
	{
		if (node->nb > node->next->nb)
			return (0);
		node = node->next;
	}
	return (1);
}

int	get_stack_size(t_stack *stack)
{
	t_node	*node;
	int		i;

	if (stack->start == NULL)
		return (0);
	node = stack->start;
	i = 1;
	while (node != stack->end)
	{
		i++;
		node = node->next;
	}
	return (i);
}
