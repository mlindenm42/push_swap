/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:14 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/16 10:42:13 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*pa (push a): Take the first element at the top of b and put it at the top of
a. Do nothing if b is empty.*/
void	pa(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->b->start == NULL)
		return ;
	ptr = remove_node_from_stack_top(stack_ptr->b);
	add_node_to_stack_top(stack_ptr->a, ptr);
	ptr = NULL;
	write(1, "pa\n", 3);
}

/*pb (push b): Take the first element at the top of a and put it at the top of
b. Do nothing if a is empty.*/
void	pb(t_stack_ptr *stack_ptr)
{
	t_node	*ptr;

	ptr = NULL;
	if (stack_ptr->a->start == NULL)
		return ;
	ptr = remove_node_from_stack_top(stack_ptr->a);
	add_node_to_stack_top(stack_ptr->b, ptr);
	ptr = NULL;
	write(1, "pb\n", 3);
}
