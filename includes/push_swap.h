/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:42:25 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/15 17:33:59 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h> //printf();

// void	free_str(char **str);

typedef struct s_node
{
	int				number;
	struct s_node	*next;
	struct s_node	*previous;
}	t_node;

typedef struct s_stack
{
	t_node	*start;
	t_node	*end;
}	t_stack;

typedef struct s_stack_ptr
{
	struct s_stack	*a;
	struct s_stack	*b;
	t_node	*buffer;
}	t_stack_ptr;

void	error(char *reason);
void	error_data(t_stack_ptr *stack_ptr, char *reason);
void	free_all(t_stack_ptr *stack_ptr);

void	init_stack(t_stack_ptr *stack_ptr, int argc, char *argv[]);

t_node	*make_node(t_stack_ptr *stack_ptr, int number);
void	add_node_to_stack_top(t_stack_ptr *stack_ptr,
			t_stack *stack, t_node *s_node);
void	add_node_to_stack_bottom(t_stack_ptr *stack_ptr,
			t_stack *stack, t_node *s_node);
t_node	*remove_node_from_stack_top(t_stack_ptr *stack_ptr, t_stack *stack);
t_node	*remove_node_from_stack_bottom(t_stack_ptr *stack_ptr, t_stack *stack);

void	sa(t_stack_ptr *stack_ptr);
void	sb(t_stack_ptr *stack_ptr);
void	ss(t_stack_ptr *stack_ptr);
#endif
