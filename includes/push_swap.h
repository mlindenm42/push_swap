/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlindenm <mlindenm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 14:42:25 by mlindenm          #+#    #+#             */
/*   Updated: 2023/05/24 13:39:23 by mlindenm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h> //NULL; write();

typedef struct s_node
{
	int				nb;
	unsigned int	pos_end;
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
	int		size;
}	t_stack_ptr;

// check.c
int		check_duplicates(t_stack_ptr *stack_ptr);
void	check_arg(t_stack_ptr *stack_ptr, int argc, char *argv[]);
// dlist_help.c
int		is_sorted(t_stack_ptr *p);
int		get_stack_size(t_stack *stack);
// dlist.c
t_node	*make_node(t_stack_ptr *stack_ptr, int number);
int		add_node_to_stack_top(t_stack *stack, t_node *node);
int		add_node_to_stack_bottom(t_stack *stack, t_node *node);
t_node	*remove_node_from_stack_top(t_stack *stack);
t_node	*remove_node_from_stack_bottom(t_stack *stack);
// error.c
void	error(char *reason);
void	error_data(t_stack_ptr *stack_ptr, char *reason);
void	free_ptrptr(t_stack_ptr *stack_ptr);
void	free_all(t_stack_ptr *stack_ptr);
// init_stack.c
void	init_stack(t_stack_ptr *stack_ptr, int argc, char *argv[]);
// push.c
void	pa(t_stack_ptr *stack_ptr);
void	pb(t_stack_ptr *stack_ptr);
// rev_rotate.c
void	rra(t_stack_ptr *stack_ptr);
void	rrb(t_stack_ptr *stack_ptr);
void	rrr(t_stack_ptr *stack_ptr);
// rotate.c
void	ra(t_stack_ptr *stack_ptr);
void	rb(t_stack_ptr *stack_ptr);
void	rr(t_stack_ptr *stack_ptr);
// sort.c
void	sort(t_stack_ptr *p);
// swap.c
void	sa(t_stack_ptr *stack_ptr);
void	sb(t_stack_ptr *stack_ptr);
void	ss(t_stack_ptr *stack_ptr);

#endif
