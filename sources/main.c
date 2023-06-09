/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 16:47:13 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/24 13:17:46 by mlindenm         ###   ########.fr       */
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
	sort(p);
	free_all(p);
	return (0);
}
