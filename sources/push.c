/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:14 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/24 19:14:26 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*pa (push a): Take the first element at the top of b and put it at the top of
a. Do nothing if b is empty.*/
void	pa(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (p->b->start == NULL)
		return ;
	ptr = remove_node_from_stack_top(p->b);
	add_node_to_stack_top(p->a, ptr);
	ptr = NULL;
	write(1, "pa\n", 3);
}

/*pb (push b): Take the first element at the top of a and put it at the top of
b. Do nothing if a is empty.*/
void	pb(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (p->a->start == NULL)
		return ;
	ptr = remove_node_from_stack_top(p->a);
	add_node_to_stack_top(p->b, ptr);
	ptr = NULL;
	write(1, "pb\n", 3);
}
