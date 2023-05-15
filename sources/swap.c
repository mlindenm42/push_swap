/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:30 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 15:51:21 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack_ptr *stack_ptr)
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = NULL;
	ptr2 = NULL;
	if (stack_ptr->a == NULL)
		error_data(stack_ptr, "No stack!\n");
	ptr1 = remove_node_from_stack_top(stack_ptr, stack_ptr->a);
	ptr2 = remove_node_from_stack_top(stack_ptr, stack_ptr->a);
	add_node_to_stack_top(stack_ptr, stack_ptr->a, ptr1);
	ptr1 = NULL;
	add_node_to_stack_top(stack_ptr, stack_ptr->a, ptr2);
	ptr2 = NULL;
}

void	sb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr1;
	t_node	*ptr2;

	ptr1 = NULL;
	ptr2 = NULL;
	if (stack_ptr->b == NULL)
		error_data(stack_ptr, "No stack!\n");
	ptr1 = remove_node_from_stack_top(stack_ptr, stack_ptr->b);
	ptr2 = remove_node_from_stack_top(stack_ptr, stack_ptr->b);
	add_node_to_stack_top(stack_ptr, stack_ptr->b, ptr1);
	ptr1 = NULL;
	add_node_to_stack_top(stack_ptr, stack_ptr->b, ptr2);
	ptr2 = NULL;
}
