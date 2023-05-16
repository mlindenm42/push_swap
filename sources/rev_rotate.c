/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:24 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/16 10:44:21 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*rra (reverse rotate a): Shift down all elements of stack a by 1. The last
element becomes the first one.*/
void	rra(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_bottom(stack_ptr->a);
	add_node_to_stack_top(stack_ptr->a, ptr);
	ptr = NULL;
	write(1, "rra\n", 4);
}

/*rrb (reverse rotate b): Shift down all elements of stack b by 1. The last
element becomes the first one.*/
void	rrb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_bottom(stack_ptr->b);
	add_node_to_stack_top(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "rrb\n", 4);
}

/*rrr : rra and rrb at the same time.*/
void	rrr(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_bottom(stack_ptr->a);
	add_node_to_stack_top(stack_ptr->a, ptr);
	ptr = NULL;
	ptr = remove_node_from_stack_bottom(stack_ptr->b);
	add_node_to_stack_top(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "rrr\n", 4);
}
