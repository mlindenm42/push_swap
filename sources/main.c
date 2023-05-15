/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:13 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 18:02:43 by mlindenm         ###   ########.fr       */
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
