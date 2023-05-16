/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:30 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/16 10:25:14 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->a == NULL)
		error_data(stack_ptr, "No stack!\n");
	if (!(stack_ptr->a->start && stack_ptr->a->start->next))
		return ;
	stack_ptr->buffer = remove_node_from_stack_top(stack_ptr->a);
	ptr = remove_node_from_stack_top(stack_ptr->a);
	add_node_to_stack_top(stack_ptr->a, stack_ptr->buffer);
	stack_ptr->buffer = NULL;
	add_node_to_stack_top(stack_ptr->a, ptr);
	ptr = NULL;
	write(1, "sa\n", 3);
}

void	sb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->b == NULL)
		error_data(stack_ptr, "No stack!\n");
	if (!(stack_ptr->b->start && stack_ptr->b->start->next))
		return ;
	stack_ptr->buffer = remove_node_from_stack_top(stack_ptr->b);
	ptr = remove_node_from_stack_top(stack_ptr->b);
	add_node_to_stack_top(stack_ptr->b, stack_ptr->buffer);
	stack_ptr->buffer = NULL;
	add_node_to_stack_top(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "sb\n", 3);
}

void	ss(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->a == NULL)
		error_data(stack_ptr, "No stack!\n");
	if (!(stack_ptr->a->start && stack_ptr->a->start->next))
		return ;
	stack_ptr->buffer = remove_node_from_stack_top(stack_ptr->a);
	ptr = remove_node_from_stack_top(stack_ptr->a);
	add_node_to_stack_top(stack_ptr->a, stack_ptr->buffer);
	stack_ptr->buffer = NULL;
	add_node_to_stack_top(stack_ptr->a, ptr);
	ptr = NULL;
	if (stack_ptr->b == NULL)
		error_data(stack_ptr, "No stack!\n");
	if (!(stack_ptr->b->start && stack_ptr->b->start->next))
		return ;
	stack_ptr->buffer = remove_node_from_stack_top(stack_ptr->b);
	ptr = remove_node_from_stack_top(stack_ptr->b);
	add_node_to_stack_top(stack_ptr->b, stack_ptr->buffer);
	stack_ptr->buffer = NULL;
	add_node_to_stack_top(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "ss\n", 3);
}
