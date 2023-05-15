/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:49:18 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 16:31:46 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> //malloc();

t_node	*make_node(t_stack_ptr *stack_ptr, int number)
{
	t_node	*ptr;

	ptr = (t_node *)malloc(sizeof(t_node));
	if (ptr == NULL)
		error_data(stack_ptr, "malloc new s_node\n");
	ptr->number = number;
	ptr->next = NULL;
	ptr->previous = NULL;
	return (ptr);
}

void	add_node_to_stack_top(t_stack_ptr *stack_ptr,
t_stack *stack, t_node *s_node)
{
	if (s_node == NULL)
		error_data(stack_ptr, "No s_node!\n");
	if (stack->start == NULL)
	{
		stack->start = s_node;
		stack->end = s_node;
		stack->start->previous = NULL;
		stack->start->next = NULL;
		return ;
	}
	s_node->next = stack->start;
	stack->start->previous = s_node;
	stack->start = s_node;
	stack->start->previous = NULL;
	return ;
}

void	add_node_to_stack_bottom(t_stack_ptr *stack_ptr,
t_stack *stack, t_node *s_node)
{
	if (s_node == NULL)
		error_data(stack_ptr, "No s_node!\n");
	if (stack->end == NULL)
	{
		stack->end = s_node;
		stack->start = s_node;
		stack->start->previous = NULL;
		stack->start->next = NULL;
		return ;
	}
	stack->end->next = s_node;
	s_node->previous = stack->end;
	stack->end = s_node;
	s_node->next = NULL;
	return ;
}

t_node	*remove_node_from_stack_top(t_stack_ptr *stack_ptr, t_stack *stack)
{
	t_node	*ptr;

	if (stack == NULL)
		error_data(stack_ptr, "No stack!\n");
	if (stack->start == NULL)
		error_data(stack_ptr, "Stack is empty!\n");
	ptr = stack->start;
	if (stack->start == stack->end)
	{
		stack->start = NULL;
		stack->end = NULL;
	}
	else
	{
		stack->start = stack->start->next;
		stack->start->previous = NULL;
	}
	ptr->previous = NULL;
	ptr->next = NULL;
	return (ptr);
}

t_node	*remove_node_from_stack_bottom(t_stack_ptr *stack_ptr, t_stack *stack)
{
	t_node	*ptr;

	if (stack == NULL)
		error_data(stack_ptr, "No stack!\n");
	if (stack->end == NULL)
		error_data(stack_ptr, "Stack is empty!\n");
	ptr = stack->end;
	if (stack->end == stack->start)
	{
		stack->end = NULL;
		stack->start = NULL;
	}
	else
	{
		stack->end = stack->end->previous;
		stack->end->next = NULL;
	}
	ptr->previous = NULL;
	ptr->next = NULL;
	return (ptr);
}
