/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:13 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/22 19:16:15 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h> //malloc();

int	main(int argc, char *argv[])
{
	t_stack_ptr	*p;

	if (argc < 2)
		return (0);
	p = (t_stack_ptr *)malloc(sizeof(t_stack_ptr));
	if (p == NULL)
		error("malloc p\n");
	init_stack(p, argc, argv);
	if (get_stack_size(p->a) == 2)
	{
		if (!is_sorted(p))
			sa(p);
	}
	else if (get_stack_size(p->a) == 3)
		sort3(p);
	else if (get_stack_size(p->a) > 3)
		sort5(p);
	free_all(p);
	return (0);
}

// #include "../push_swap/libraries/libft/libft.h" //ft_putnbr_fd();
// void	print_stack(t_stack_ptr	*p)
// {
// 	t_node	*ptr;

// 	write(1, "Stack A: ", 9);
// 	if (p->a->start == NULL)
// 		write(1, "-", 1);
// 	ptr = p->a->start;
// 	while (ptr != NULL)
// 	{
// 		ft_putnbr_fd(ptr->nb, 1);
// 		write(1, " ", 1);
// 		ptr = ptr->next;
// 	}
// 	write(1, "\n", 1);
// 	write(1, "Stack B: ", 9);
// 	if (p->b->start == NULL)
// 		write(1, "-", 1);
// 	ptr = p->b->start;
// 	while (ptr != NULL)
// 	{
// 		ft_putnbr_fd(ptr->nb, 1);
// 		write(1, " ", 1);
// 		ptr = ptr->next;
// 	}
// 	write(1, "\n", 1);
// }
