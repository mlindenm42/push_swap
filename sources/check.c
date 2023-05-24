/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:43:02 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/24 13:42:05 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../libraries/libft/libft.h" //ft_isdigit(); ft_split();

static int	check_string(char *str)
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

static int	check_duplicates_recursive(t_node *node, int number)
{
	if (node == NULL)
		return (1);
	if (node->nb == number)
		return (0);
	return (check_duplicates_recursive(node->next, number));
}

int	check_duplicates(t_stack_ptr *p)
{
	t_node	*node;

	node = p->a->start;
	while (node != p->a->end)
	{
		if (!check_duplicates_recursive(node->next, node->nb))
			return (0);
		node = node->next;
	}
	return (1);
}

void	check_arg(t_stack_ptr *p, int argc, char *argv[])
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	p->ptrptr = NULL;
	while (i < argc)
	{
		p->ptrptr = ft_split(argv[i++], ' ');
		if (p->ptrptr == NULL)
			error_data(p, "split failed!\n");
		while (*(p->ptrptr + j) != NULL)
		{
			if (!check_string(*(p->ptrptr + j)))
				error_data(p, "invalid characters as arguments!\n");
			j++;
		}
		j = 0;
		free_ptrptr(p);
	}
}
