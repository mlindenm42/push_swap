/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:27 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/16 10:43:10 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*ra (rotate a): Shift up all elements of stack a by 1. The first element
becomes the last one.*/
void	ra(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_top(stack_ptr->a);
	add_node_to_stack_bottom(stack_ptr->a, ptr);
	ptr = NULL;
	write(1, "ra\n", 3);
}

/*rb (rotate b): Shift up all elements of stack b by 1. The first element
becomes the last one.*/
void	rb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	ptr = remove_node_from_stack_top(stack_ptr->b);
	add_node_to_stack_bottom(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "rb\n", 3);
}

/*rr : ra and rb at the same time.*/
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
