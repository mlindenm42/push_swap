/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:02 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 10:24:01 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_isdigit();
#include <stdlib.h> //malloc();

static int	check_duplicates_recursive(t_node *node, int number)
{
	if (node == NULL)
		return (1);
	if (node->number == number)
		return (0);
	return (check_duplicates_recursive(node->next, number));
}

int	check_duplicates(t_stack_ptr *stack_ptr)
{
	t_node	*node;

	node = stack_ptr->a->start;
	while (node != stack_ptr->a->end)
	{
		if (!check_duplicates_recursive(node->next, node->number))
			return (0);
		node = node->next;
	}
	return (1);
}

static int	check_string(char *str)
{
	int	i;

	i = 0;
	if (*(str) == '+' || *(str) == '-')
		i++;
	if (*(str + i) < '0' || *(str + i) > '9')
		return (0);
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= '0' && *(str + i) <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

void	check_arg(t_stack_ptr *stack_ptr, int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	stack_ptr->ptrptr = NULL;
	while (i < argc)
	{
		stack_ptr->ptrptr = ft_split(argv[i++], ' ');
		if (stack_ptr->ptrptr == NULL)
			error_data(stack_ptr, "split failed!\n");
		while (*(stack_ptr->ptrptr + j) != NULL)
		{
			if (!check_string(*(stack_ptr->ptrptr + j)))
				error_data(stack_ptr, "invalid characters as arguments!\n");
			j++;
		}
		j = 0;
		free_ptrptr(stack_ptr);
	}
}
