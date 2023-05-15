/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:30 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 17:36:31 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->a == NULL)
		error_data(stack_ptr, "No stack!\n");
	stack_ptr->buffer = remove_node_from_stack_top(stack_ptr, stack_ptr->a);
	ptr = remove_node_from_stack_top(stack_ptr, stack_ptr->a);
	add_node_to_stack_top(stack_ptr, stack_ptr->a, stack_ptr->buffer);
	stack_ptr->buffer = NULL;
	add_node_to_stack_top(stack_ptr, stack_ptr->a, ptr);
	ptr = NULL;
}

void	sb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->b == NULL)
		error_data(stack_ptr, "No stack!\n");
	stack_ptr->buffer = remove_node_from_stack_top(stack_ptr, stack_ptr->b);
	ptr = remove_node_from_stack_top(stack_ptr, stack_ptr->b);
	add_node_to_stack_top(stack_ptr, stack_ptr->b, stack_ptr->buffer);
	stack_ptr->buffer = NULL;
	add_node_to_stack_top(stack_ptr, stack_ptr->b, ptr);
	ptr = NULL;
}

void	ss(t_stack_ptr *stack_ptr)
{
	sa(stack_ptr);
	sb(stack_ptr);
}
