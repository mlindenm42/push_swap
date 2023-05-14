/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:42:25 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 00:12:28 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //printf();

void	error(char *reason);
// void	free_str(char **str);

typedef struct node
{
	int				number;
	struct node	*next;
	struct node	*previous;
}					s_node;

struct stack
{
	struct node	*start;
	struct node	*end;
};

s_node	*make_node(int number);
void	add_node_to_stack_bottom(struct stack *stack, s_node *node);
s_node	*remove_node_from_stack_bottom(struct stack *stack);
void	print_stack(struct stack *stack);

#endif
