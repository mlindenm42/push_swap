/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:36:03 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 10:15:56 by mlindenm         ###   ########.fr       */
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
	free_all(stack_ptr);
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	exit(EXIT_FAILURE);
}

void	free_ptrptr(t_stack_ptr *stack_ptr)
{
	int	i;

	i = 0;
	if (stack_ptr->ptrptr == NULL)
		return ;
	while (*(stack_ptr->ptrptr + i) != NULL)
	{
		free(*(stack_ptr->ptrptr + i));
		*(stack_ptr->ptrptr + i) = NULL;
		i++;
	}
	if (stack_ptr->ptrptr != NULL)
	{
		free(stack_ptr->ptrptr);
		stack_ptr->ptrptr = NULL;
	}
}

void	free_all(t_stack_ptr *stack_ptr)
{
	free_ptrptr(stack_ptr);
	while (stack_ptr->a->start != NULL)
		free(remove_node_from_stack_top(stack_ptr->a));
	while (stack_ptr->b->start != NULL)
		free(remove_node_from_stack_top(stack_ptr->b));
	if (stack_ptr->buffer != NULL)
	{
		free(stack_ptr->buffer);
		stack_ptr->buffer = NULL;
	}
	if (stack_ptr->a != NULL)
	{
		free(stack_ptr->a);
		stack_ptr->a = NULL;
	}
	if (stack_ptr->b != NULL)
	{
		free(stack_ptr->b);
		stack_ptr->b = NULL;
	}
	if (stack_ptr != NULL)
	{
		free(stack_ptr);
		stack_ptr = NULL;
	}
}
