/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:49:18 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/23 15:37:04 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> //malloc();

t_node	*make_node(t_stack_ptr *p, int number)
{
	static unsigned int	counter = 0;
	t_node				*ptr;

	counter++;
	if (counter >= 4294967295)
		error_data(p, "list too long!\n");
	ptr = (t_node *)malloc(sizeof(t_node));
	if (ptr == NULL)
		error_data(p, "malloc node failed!\n");
	ptr->nb = number;
	ptr->next = NULL;
	ptr->previous = NULL;
	return (ptr);
}

int	add_node_to_stack_top(t_stack *stack, t_node *node)
{
	if (stack == NULL)
		return (0);
	if (node == NULL)
		return (0);
	if (stack->start == NULL)
	{
		stack->start = node;
		stack->end = node;
		stack->start->previous = NULL;
		stack->start->next = NULL;
		return (1);
	}
	node->next = stack->start;
	stack->start->previous = node;
	stack->start = node;
	stack->start->previous = NULL;
	return (1);
}

int	add_node_to_stack_bottom(t_stack *stack, t_node *node)
{
	if (stack == NULL)
		return (0);
	if (node == NULL)
		return (0);
	if (stack->end == NULL)
	{
		stack->end = node;
		stack->start = node;
		stack->start->previous = NULL;
		stack->start->next = NULL;
		return (1);
	}
	stack->end->next = node;
	node->previous = stack->end;
	stack->end = node;
	node->next = NULL;
	return (1);
}

t_node	*remove_node_from_stack_top(t_stack *stack)
{
	t_node	*ptr;

	if (stack == NULL)
		return (NULL);
	if (stack->start == NULL)
		return (NULL);
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

t_node	*remove_node_from_stack_bottom(t_stack *stack)
{
	t_node	*ptr;

	if (stack == NULL)
		return (NULL);
	if (stack->end == NULL)
		return (NULL);
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
