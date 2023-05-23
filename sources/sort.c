/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:36 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/23 16:23:35 by mlindenm         ###   ########.fr       */
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

void	idk(t_stack_ptr *p, int pos)
{
	if (pos == 1)
	{
		pb(p);
		return ;
	}
	if (pos - ((get_stack_size(p->a) - 1) / 2) <= 1)
	{
		while (pos > 1)
		{
			ra(p);
			pos--;
		}
	}
	else
	{
		while (pos <= get_stack_size(p->a))
		{
			rra(p);
			pos++;
		}
	}
}

void	push_smallest_a_to_b(t_stack_ptr *p)
{
	t_node	*node;
	t_node	*smallest;
	int		i;
	int		pos;

	i = 1;
	pos = 0;
	node = p->a->start;
	smallest = p->a->start;
	while (node != NULL)
	{
		if (smallest->nb > node->nb)
		{
			smallest = node;
			pos = i;
		}
		i++;
		node = node->next;
	}
	idk(p, pos);
	pb(p);
}

void	sort_small(t_stack_ptr *p)
{
	if (!is_sorted(p) && get_stack_size(p->a) == 5)
		push_smallest_a_to_b(p);
	if (!is_sorted(p) && get_stack_size(p->a) == 4)
		push_smallest_a_to_b(p);
	while (!is_sorted(p))
	{
		if (p->a->start->nb > p->a->start->next->nb
			&& p->a->start->next->nb < p->a->start->next->next->nb)
			sa(p);
		else if (p->a->start->nb < p->a->start->next->nb
			&& p->a->start->next->nb > p->a->start->next->next->nb)
			rra(p);
		else if (p->a->start->nb > p->a->start->next->nb
			&& p->a->start->next->nb > p->a->start->next->next->nb)
			ra(p);
	}
	pa(p);
	pa(p);
}

// void	sort_big(t_stack_ptr *p)
// {
// 	static int	i = 31;

// 	if (is_sorted(p))
// 		return ;


// }
