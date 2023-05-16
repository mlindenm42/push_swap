/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:27 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/16 09:36:55 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_top(stack_ptr->a);
	add_node_to_stack_bottom(stack_ptr->a, ptr);
	ptr = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_top(stack_ptr->b);
	add_node_to_stack_bottom(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_top(stack_ptr->a);
	add_node_to_stack_bottom(stack_ptr->a, ptr);
	ptr = NULL;
	ptr = remove_node_from_stack_top(stack_ptr->b);
	add_node_to_stack_bottom(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "rr\n", 3);
}
