/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:02 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 00:10:55 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_isdigit();
#include <stdlib.h> //malloc();

int	atoi_push_swap(t_stack_ptr *stack_ptr, const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '\007' || str[i] == '\010')
		error_data(stack_ptr, "non-valid character\n");
	while ((str[i] >= 7 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (i > 0 && str[i - 1] == '-')
		sign = -1;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		if (res * sign > 2147483647)
			error_data(stack_ptr, "non-valid character\n");
		if (res * sign < -2147483648)
			error_data(stack_ptr, "non-valid character\n");
		i++;
	}
	return (sign * res);
}

void	init_stacks(t_stack_ptr *stack_ptr)
{
	stack_ptr->a = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (stack_ptr->a == NULL)
		error_data(stack_ptr, "malloc stack_ptr->a\n");
	stack_ptr->a->start = NULL;
	stack_ptr->a->end = NULL;
	stack_ptr->b = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (stack_ptr->b == NULL)
		error_data(stack_ptr, "malloc stack_ptr->b\n");
	stack_ptr->b->start = NULL;
	stack_ptr->b->end = NULL;
	stack_ptr->buffer = NULL;
	stack_ptr->ptrptr = NULL;
}

int	check_string(char *str)
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
			{
				free_ptrptr(stack_ptr);
				error_data(stack_ptr, "invalid characters as arguments!\n");
			}
			j++;
		}
		j = 0;
		free_ptrptr(stack_ptr);
	}
}

void	from_arg_to_stack(t_stack_ptr *stack_ptr, int argc, char *argv[])
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
			add_node_to_stack_bottom(stack_ptr->a,
				make_node(stack_ptr, atoi_push_swap(stack_ptr,
						*(stack_ptr->ptrptr + j))));
			j++;
		}
		j = 0;
		free_ptrptr(stack_ptr);
	}
}

int	check_duplicates_recursive(t_node *node, int number)
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

void	init_stack(t_stack_ptr *stack_ptr, int argc, char *argv[])
{
	init_stacks(stack_ptr);
	check_arg(stack_ptr, argc, argv);
	from_arg_to_stack(stack_ptr, argc, argv);
	if (stack_ptr->a->start == NULL)
		error_data(stack_ptr, "empty list!\n");
	if (!check_duplicates(stack_ptr))
		error_data(stack_ptr, "duplicates!\n");
}
