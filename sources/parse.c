/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:02 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/16 09:34:27 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_atoi();
#include <stdlib.h> //malloc();

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
}

void	init_stack(t_stack_ptr *stack_ptr, int argc, char *argv[])
{
	char	**ptrptr;
	int		i;
	int		j;

	ptrptr = NULL;
	i = 1;
	j = 0;
	init_stacks(stack_ptr);
	while (i < argc)
	{
		ptrptr = ft_split(argv[i++], ' ');
		if (ptrptr == NULL)
			error_data(stack_ptr, "split failed!\n");
		j = 0;
		while (*(ptrptr + j) != NULL)
		{
			if (*(ptrptr + j)[0] == '0')
			{
				add_node_to_stack_bottom(stack_ptr->a,
					make_node(0));
				free(*(ptrptr + j++));
			}
			else
			{
				free(*(ptrptr + j));
				if (ft_atoi(*(ptrptr + j)) == 0)
				{
					while (*(ptrptr + j + 1) != NULL)
						free(*(ptrptr + j++ + 1));
					free(ptrptr);
					error_data(stack_ptr, "atoi failed!\n");
				}
				add_node_to_stack_bottom(stack_ptr->a,
					make_node(ft_atoi(*(ptrptr + j++))));
			}
		}
		free(ptrptr);
	}
}

// void	init_stack(t_stack_ptr *stack_ptr, int argc, char *argv[])
// {
// 	char	**ptrptr;
// 	char	**ptrptr_cp;
// 	int		i;

// 	ptrptr = NULL;
// 	i = 1;
// 	init_stacks(stack_ptr);
// 	while (i < argc)
// 	{
// 		ptrptr = ft_split(argv[i++], ' ');
// 		if (ptrptr == NULL)
// 			error_data(stack_ptr, "split failed!\n");
// 		ptrptr_cp = ptrptr;
// 		while (*(ptrptr) != NULL)
// 		{
// 			if (*(ptrptr)[0] == '0')
// 			{
// 				add_node_to_stack_bottom(stack_ptr, stack_ptr->a,
// 					make_node(stack_ptr, 0));
// 				free(*(ptrptr++));
// 			}
// 			else
// 			{
// 				if (ft_atoi(*(ptrptr)) == 0)
// 				{
// 					free(*(ptrptr++));
// 					while (*(ptrptr) != NULL)
// 						free(*(ptrptr++));
// 					free(ptrptr_cp);
// 					error_data(stack_ptr, "atoi failed!\n");
// 				}
// 				add_node_to_stack_bottom(stack_ptr, stack_ptr->a,
// 					make_node(stack_ptr, ft_atoi(*(ptrptr))));
// 				free(*(ptrptr++));
// 			}
// 		}
// 		free(ptrptr_cp);
// 	}
// }
