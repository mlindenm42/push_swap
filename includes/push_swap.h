/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:42:25 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/23 10:56:25 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //NULL; write();
# include <stdio.h> //printf();

typedef struct s_node
{
	int				nb;
	// int				binary[32];
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
	t_stack	*a;
	t_stack	*b;
	t_node	*buffer;
	char	**ptrptr;
}	t_stack_ptr;

void	error(char *reason);
void	error_data(t_stack_ptr *stack_ptr, char *reason);
void	free_ptrptr(t_stack_ptr *stack_ptr);
void	free_all(t_stack_ptr *stack_ptr);

void	init_stack(t_stack_ptr *stack_ptr, int argc, char *argv[]);
void	check_arg(t_stack_ptr *stack_ptr, int argc, char *argv[]);
int		check_duplicates(t_stack_ptr *stack_ptr);

t_node	*make_node(t_stack_ptr *stack_ptr, int number);
int		add_node_to_stack_top(t_stack *stack, t_node *node);
int		add_node_to_stack_bottom(t_stack *stack, t_node *node);
t_node	*remove_node_from_stack_top(t_stack *stack);
t_node	*remove_node_from_stack_bottom(t_stack *stack);

void	sa(t_stack_ptr *stack_ptr);
void	sb(t_stack_ptr *stack_ptr);
void	ss(t_stack_ptr *stack_ptr);
void	pa(t_stack_ptr *stack_ptr);
void	pb(t_stack_ptr *stack_ptr);
void	ra(t_stack_ptr *stack_ptr);
void	rb(t_stack_ptr *stack_ptr);
void	rr(t_stack_ptr *stack_ptr);
void	rra(t_stack_ptr *stack_ptr);
void	rrb(t_stack_ptr *stack_ptr);
void	rrr(t_stack_ptr *stack_ptr);

void	sort3(t_stack_ptr *stack_ptr);
void	sort5(t_stack_ptr *stack_ptr);
int		get_stack_size(t_stack *stack);
int		is_sorted(t_stack_ptr *p);
#endif
