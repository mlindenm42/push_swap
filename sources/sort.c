/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:36 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 19:03:47 by mlindenm         ###   ########.fr       */
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

void	sort3(t_stack_ptr *p)
{
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
	pb(p);
}

void	sort5(t_stack_ptr *p)
{
	push_smallest_a_to_b(p);
	push_smallest_a_to_b(p);
	while (!is_sorted(p))
	{
		if (p->a->start->nb < p->a->start->next->nb
			&& p->a->start->next->nb < p->a->start->next->next->nb)
			return ;
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
