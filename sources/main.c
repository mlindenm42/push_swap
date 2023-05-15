/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:13 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 11:20:51 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_strlen(); ft_atoi();
#include <stdlib.h> //malloc();

void	error(char *reason)
{
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[])
{
	int				i;
	struct stack	*stack_a;
	struct stack	*stack_b;
	s_node			*ptr;

	if (argc < 2)
		error("Not enough arguments!\n");
	i = 1;
	stack_a = (struct stack *)malloc(sizeof(struct stack));
	if (stack_a == NULL)
		error("malloc stack_a\n");
	stack_a->start = NULL;
	stack_a->end = NULL;
	while (i < argc)
		add_node_to_stack_bottom(stack_a, make_node(atoi(argv[i++])));
	stack_b = (struct stack *)malloc(sizeof(struct stack));
	if (stack_b == NULL)
		error("malloc stack_b\n");
	stack_b->start = NULL;
	stack_b->end = NULL;
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	ptr = remove_node_from_stack_top(stack_a);
	add_node_to_stack_bottom(stack_b, ptr);
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	ptr = remove_node_from_stack_top(stack_a);
	add_node_to_stack_bottom(stack_b, ptr);
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	ptr = remove_node_from_stack_top(stack_a);
	add_node_to_stack_bottom(stack_b, ptr);
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	ptr = remove_node_from_stack_top(stack_b);
	add_node_to_stack_bottom(stack_a, ptr);
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	ptr = remove_node_from_stack_top(stack_b);
	add_node_to_stack_bottom(stack_a, ptr);
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);

	ptr = remove_node_from_stack_top(stack_b);
	add_node_to_stack_bottom(stack_a, ptr);
	printf("Stack A:\n");
	print_stack(stack_a);
	printf("Stack B:\n");
	print_stack(stack_b);
	return (0);
}
