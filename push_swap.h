/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:38 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/17 14:27:23 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h" 
# include <unistd.h>
# include <stdlib.h>

typedef enum e_parameter{
	NOPARAMETER = -1,
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr,
}	t_paramiter;

typedef struct s_stack{
	int				number;
	struct s_stack	*next;
}	t_stack;

int		is_valid_input(const char *stack);
int		is_duplicate(t_stack *a);
int		error(void);
int		check_saving(const char **stack, t_stack **stack_a);
void	free_stack(t_stack *stack);
t_stack	*stacklast(t_stack *stack);
t_stack	*stack_penultimate(t_stack *stack);
void	stackadd_top(t_stack **stack, t_stack *element);
void	stackadd_bottom(t_stack **stack, t_stack *element);
t_stack	*stacknew(int number);
void	push(t_stack **stack_sender, t_stack **stack_target);
void	rv_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);
void	compute_move(int move, t_stack **a, t_stack **b);
void	print_move(int move);




void	test_move (t_stack **a);

#endif
