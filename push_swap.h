/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:38 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/03/19 18:51:30 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h" 
# include <unistd.h>
# include <stdlib.h>

typedef enum e_parameter{
	NOPARAMETER = 1,
	sa = 2,
	sb = 3,
	ss = 4,
	pa = 5,
	pb = 6,
	ra = 7,
	rb = 8,
	rr = 9,
	rra = 10,
	rrb = 11,
	rrr = 12,
}	t_paramiter;

typedef struct s_stack{
	int		number;
	s_stack	*next;
}	t_stack;

int		is_valid_input(char **stack);
int		error(void);
int		save_stack(char **stack, t_stack *stack_a);
void	free_stack(t_stack *stack);
t_stack	*stacklast(t_stack *stack);
void	stackadd_top(t_stack **stack, t_stack *element);
void	stackadd_bottom(t_stack **stack, t_stack *element);
t_stack	*stacknew(int number);
t_stack	*push(t_stack **stack_sender, t_stack **stack_target);
void	rv_rotate(t_stack **stack);
void	rotate(t_stack **stack);
void	swap(t_stack **stack);
#endif
