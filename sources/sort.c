/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:36 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 16:07:16 by mlindenm         ###   ########.fr       */
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
	// printf("OK\n");
	return (1);
}

void	sort3(t_stack_ptr *p)
{
	while (!is_sorted(p))
	{
		// 0 1 2
		// if (p->a->start->nb < p->a->start->next->nb
		// 	&& p->a->start->next->nb < p->a->start->next->next->nb)
		// 	return ;
		// 1 0 2 -> 0 1 2
		// 2 0 1 -> 0 2 1
		if (p->a->start->nb > p->a->start->next->nb
			&& p->a->start->next->nb < p->a->start->next->next->nb)
			sa(p);
		// 1 2 0 -> 0 1 2
		// 0 2 1 -> 2 1 0
		else if (p->a->start->nb < p->a->start->next->nb
			&& p->a->start->next->nb > p->a->start->next->next->nb)
			rra(p);
		// 2 1 0 -> 1 0 2
		else if (p->a->start->nb > p->a->start->next->nb
			&& p->a->start->next->nb > p->a->start->next->next->nb)
			ra(p);
	}
}
