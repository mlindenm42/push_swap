/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:49:18 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 11:20:20 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> //malloc();

s_node	*make_node(int number)
{
	s_node	*ptr;

	ptr = (s_node *)malloc(sizeof(s_node));
	if (ptr == NULL)
		error("malloc new node\n");
	ptr->number = number;
	ptr->next = NULL;
	ptr->previous = NULL;
	return (ptr);
}

void	add_node_to_stack_top(struct stack *stack, s_node *node)
{
	if (node == NULL)
		error("No node!\n");
	if (stack->start == NULL)
	{
		stack->start = node;
		stack->end = node;
		stack->start->previous = NULL;
		stack->start->next = NULL;
		return ;
	}
	node->next = stack->start;
	stack->start->previous = node;
	stack->start = node;
	stack->start->previous = NULL;
	return ;
}

void	add_node_to_stack_bottom(struct stack *stack, s_node *node)
{
	if (node == NULL)
		error("No node!\n");
	if (stack->end == NULL)
	{
		stack->end = node;
		stack->start = node;
		stack->start->previous = NULL;
		stack->start->next = NULL;
		return ;
	}
	stack->end->next = node;
	node->previous = stack->end;
	stack->end = node;
	node->next = NULL;
	return ;
}

s_node	*remove_node_from_stack_top(struct stack *stack)
{
	s_node	*ptr;

	if (stack == NULL)
		error("No stack!\n");
	if (stack->start == NULL)
		error("No node!\n");
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

s_node	*remove_node_from_stack_bottom(struct stack *stack)
{
	s_node	*ptr;

	if (stack == NULL)
		error("No stack!\n");
	if (stack->end == NULL)
		error("No node!\n");
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

void	print_stack(struct stack *stack)
{
	s_node	*ptr;

	if (stack == NULL)
		error("No Stack!\n");
	if (stack->start == NULL)
		printf("-");
	ptr = stack->start;
	while (ptr != NULL)
	{
		printf("%d ", ptr->number);
		ptr = ptr->next;
	}
	printf("\n");
}
