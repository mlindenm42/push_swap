/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 11:05:36 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/28 13:43:44 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	psab_help(t_stack_ptr *p, int pos)
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

static void	push_smallest_a_to_b(t_stack_ptr *p)
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
	psab_help(p, pos);
	pb(p);
}

static void	sort_small(t_stack_ptr *p)
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

static void	sort_big(t_stack_ptr *p)
{
	int	max_index;
	int	index;
	int	i;

	max_index = 0;
	while (((p->size - 1) >> max_index) != 0)
		max_index++;
	index = 0;
	while (index < max_index)
	{
		i = 0;
		while (i++ < p->size)
		{
			if (((p->a->start->pos_end >> index) & 1) == 1)
				ra(p);
			else
				pb(p);
		}
		while (p->b->start != NULL)
			pa(p);
		index++;
	}
}

void	sort(t_stack_ptr *p)
{
	if (is_sorted(p))
		return ;
	if (get_stack_size(p->a) == 2)
	{
		if (!is_sorted(p))
			sa(p);
	}
	else if (get_stack_size(p->a) >= 3 && get_stack_size(p->a) <= 5)
		sort_small(p);
	else if (get_stack_size(p->a) > 5)
		sort_big(p);
}
