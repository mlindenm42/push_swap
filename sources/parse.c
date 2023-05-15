/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:02 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 17:08:36 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_atoi();
#include <stdlib.h> //malloc();

void	init_stack(t_stack_ptr *stack_ptr, int max, char *argv[])
{
	int	i;

	i = 1;
	stack_ptr->a = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (stack_ptr->a == NULL)
		error_data(stack_ptr, "malloc stack_ptr->a\n");
	stack_ptr->a->start = NULL;
	stack_ptr->a->end = NULL;
	while (i < max)
		add_node_to_stack_bottom(stack_ptr, stack_ptr->a,
			make_node(stack_ptr, ft_atoi(argv[i++])));
	stack_ptr->b = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (stack_ptr->b == NULL)
		error_data(stack_ptr, "malloc stack_ptr->b\n");
	stack_ptr->b->start = NULL;
	stack_ptr->b->end = NULL;
}
