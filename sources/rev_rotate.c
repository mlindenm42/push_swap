/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:24 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 14:38:27 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*rra (reverse rotate a): Shift down all elements of stack a by 1. The last
element becomes the first one.*/
void	rra(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (!p->a->end)
		return ;
	ptr = remove_node_from_stack_bottom(p->a);
	add_node_to_stack_top(p->a, ptr);
	ptr = NULL;
	write(1, "rra\n", 4);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1. The last
element becomes the first one.*/
void	rrb(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (!p->b->end)
		return ;
	ptr = remove_node_from_stack_bottom(p->b);
	add_node_to_stack_top(p->b, ptr);
	ptr = NULL;
	write(1, "rrb\n", 4);
}

/*rrr : rra and rrb at the same time.*/
void	rrr(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (!p->a->end && !p->b->end)
		return ;
	ptr = remove_node_from_stack_bottom(p->a);
	add_node_to_stack_top(p->a, ptr);
	ptr = NULL;
	ptr = remove_node_from_stack_bottom(p->b);
	add_node_to_stack_top(p->b, ptr);
	ptr = NULL;
	write(1, "rrr\n", 4);
}
