/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:36:03 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 17:08:10 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_strlen();

void	error(char *reason)
{
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	exit(EXIT_FAILURE);
}

void	error_data(t_stack_ptr *stack_ptr, char *reason)
{
	while (stack_ptr->a->start != NULL)
		free(remove_node_from_stack_top(stack_ptr, stack_ptr->a));
	while (stack_ptr->b->start != NULL)
		free(remove_node_from_stack_top(stack_ptr, stack_ptr->b));
	free(stack_ptr->a);
	free(stack_ptr->b);
	free(stack_ptr);
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	exit(EXIT_FAILURE);
}

void	free_all(t_stack_ptr *stack_ptr)
{
	while (stack_ptr->a->start != NULL)
		free(remove_node_from_stack_top(stack_ptr, stack_ptr->a));
	while (stack_ptr->b->start != NULL)
		free(remove_node_from_stack_top(stack_ptr, stack_ptr->b));
	free(stack_ptr->a);
	free(stack_ptr->b);
	free(stack_ptr);
}
