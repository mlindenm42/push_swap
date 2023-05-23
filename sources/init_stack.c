/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 10:19:42 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/23 16:22:41 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_isdigit(); ft_split();
#include <stdlib.h> //malloc();

void	add_end_pos(t_stack_ptr *p)
{
	t_node	*ptr;
	t_node	*ptr2;
	int		i;
	int		pos;

	ptr = p->a->start;
	while (ptr != NULL)
	{
		pos = 0;
		ptr2 = p->a->start;
		while (ptr2 != NULL)
		{
			if (ptr->nb > ptr2->nb)
				pos++;
			ptr2 = ptr2->next;
		}
		ptr->pos_end = pos;
		i = 31;
		while (i >= 0)
		{
			ptr->pos_end_binary[i--] = pos % 2;
			pos /= 2;
		}
		ptr = ptr->next;
	}
}

static int	atoi_push_swap(t_stack_ptr *p, const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '\007' || str[i] == '\010')
		error_data(p, "non-valid character\n");
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
			error_data(p, "non-valid character\n");
		if (res * sign < -2147483648)
			error_data(p, "non-valid character\n");
		i++;
	}
	return (sign * res);
}

static void	from_arg_to_stack(t_stack_ptr *p, int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		p->ptrptr = ft_split(argv[i++], ' ');
		if (p->ptrptr == NULL)
			error_data(p, "split failed!\n");
		while (*(p->ptrptr + j) != NULL)
		{
			add_node_to_stack_bottom(p->a,
				make_node(p, atoi_push_swap(p, *(p->ptrptr + j))));
			j++;
		}
		j = 0;
		free_ptrptr(p);
	}
}

static void	init_ptrs(t_stack_ptr *p)
{
	p->a = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (p->a == NULL)
		error_data(p, "malloc p->a\n");
	p->a->start = NULL;
	p->a->end = NULL;
	p->b = (struct s_stack *)malloc(sizeof(struct s_stack));
	if (p->b == NULL)
		error_data(p, "malloc p->b\n");
	p->b->start = NULL;
	p->b->end = NULL;
	p->buffer = NULL;
	p->ptrptr = NULL;
}

void	init_stack(t_stack_ptr *p, int argc, char *argv[])
{
	init_ptrs(p);
	check_arg(p, argc, argv);
	from_arg_to_stack(p, argc, argv);
	if (p->a->start == NULL)
		error_data(p, "empty list!\n");
	if (!check_duplicates(p))
		error_data(p, "duplicates!\n");
	add_end_pos(p);
}
