/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:13 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 21:08:32 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> //malloc();

int	main(int argc, char *argv[])
{
	t_stack_ptr	*stack_ptr;

	if (argc < 2)
		error("Not enough arguments!\n");
	stack_ptr = (t_stack_ptr *)malloc(sizeof(t_stack_ptr));
	if (stack_ptr == NULL)
		error("malloc stack_ptr\n");
	init_stack(stack_ptr, argc, argv);
	free_all(stack_ptr);
	return (0);
}

// #include "../push_swap/libraries/libft/libft.h" //ft_putnbr_fd();
// void	print_stack(t_stack_ptr	*stack_ptr)
// {
// 	t_node	*ptr;

// 	write(1, "Stack A: ", 9);
// 	if (stack_ptr->a->start == NULL)
// 		write(1, "-", 1);
// 	ptr = stack_ptr->a->start;
// 	while (ptr != NULL)
// 	{
// 		ft_putnbr_fd(ptr->number, 1);
// 		write(1, " ", 1);
// 		ptr = ptr->next;
// 	}
// 	write(1, "\n", 1);
// 	write(1, "Stack B: ", 9);
// 	if (stack_ptr->b->start == NULL)
// 		write(1, "-", 1);
// 	ptr = stack_ptr->b->start;
// 	while (ptr != NULL)
// 	{
// 		ft_putnbr_fd(ptr->number, 1);
// 		write(1, " ", 1);
// 		ptr = ptr->next;
// 	}
// 	write(1, "\n", 1);
// }
