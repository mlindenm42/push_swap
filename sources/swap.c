/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:35:30 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 14:39:53 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if
there is only one or no elements.*/
void	sa(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (p->a == NULL)
		error_data(p, "No stack!\n");
	if (!(p->a->start && p->a->start->next))
		return ;
	p->buffer = remove_node_from_stack_top(p->a);
	ptr = remove_node_from_stack_top(p->a);
	add_node_to_stack_top(p->a, p->buffer);
	p->buffer = NULL;
	add_node_to_stack_top(p->a, ptr);
	ptr = NULL;
	write(1, "sa\n", 3);
}

/*sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if
there is only one or no elements.*/
void	sb(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (p->b == NULL)
		error_data(p, "No stack!\n");
	if (!(p->b->start && p->b->start->next))
		return ;
	p->buffer = remove_node_from_stack_top(p->b);
	ptr = remove_node_from_stack_top(p->b);
	add_node_to_stack_top(p->b, p->buffer);
	p->buffer = NULL;
	add_node_to_stack_top(p->b, ptr);
	ptr = NULL;
	write(1, "sb\n", 3);
}

/*ss : sa and sb at the same time.*/
void	ss(t_stack_ptr *p)
{
	t_node	*ptr;

	ptr = NULL;
	if (p->a == NULL)
		error_data(p, "No stack!\n");
	if (!(p->a->start && p->a->start->next))
		return ;
	p->buffer = remove_node_from_stack_top(p->a);
	ptr = remove_node_from_stack_top(p->a);
	add_node_to_stack_top(p->a, p->buffer);
	p->buffer = NULL;
	add_node_to_stack_top(p->a, ptr);
	ptr = NULL;
	if (p->b == NULL)
		error_data(p, "No stack!\n");
	if (!(p->b->start && p->b->start->next))
		return ;
	p->buffer = remove_node_from_stack_top(p->b);
	ptr = remove_node_from_stack_top(p->b);
	add_node_to_stack_top(p->b, p->buffer);
	p->buffer = NULL;
	add_node_to_stack_top(p->b, ptr);
	ptr = NULL;
	write(1, "ss\n", 3);
}
