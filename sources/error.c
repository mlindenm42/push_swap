/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:36:03 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/17 14:36:44 by mlindenm         ###   ########.fr       */
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

void	error_data(t_stack_ptr *p, char *reason)
{
	free_all(p);
	write(2, "Error\n", 6);
	write(2, reason, ft_strlen(reason));
	exit(EXIT_FAILURE);
}

void	free_ptrptr(t_stack_ptr *p)
{
	int	i;

	i = 0;
	if (p->ptrptr == NULL)
		return ;
	while (*(p->ptrptr + i) != NULL)
	{
		free(*(p->ptrptr + i));
		*(p->ptrptr + i) = NULL;
		i++;
	}
	if (p->ptrptr != NULL)
	{
		free(p->ptrptr);
		p->ptrptr = NULL;
	}
}

void	free_all(t_stack_ptr *p)
{
	free_ptrptr(p);
	while (p->a->start != NULL)
		free(remove_node_from_stack_top(p->a));
	while (p->b->start != NULL)
		free(remove_node_from_stack_top(p->b));
	if (p->buffer != NULL)
	{
		free(p->buffer);
		p->buffer = NULL;
	}
	if (p->a != NULL)
	{
		free(p->a);
		p->a = NULL;
	}
	if (p->b != NULL)
	{
		free(p->b);
		p->b = NULL;
	}
	if (p != NULL)
	{
		free(p);
		p = NULL;
	}
}
