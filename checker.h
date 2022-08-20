/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 14:39:09 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 14:40:21 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
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
	int				num;
	int				idx;
	struct s_stack	*next;
}	t_stack;

void	process_move(char *move, t_stack **a, t_stack **b);
void	read_sort(t_stack **a, t_stack **b);
int		is_sorted(t_stack **a);
void	compute_move(int move, t_stack **a, t_stack **b);
int		is_valid_input(const char *stack);
int		is_duplicate(t_stack *a);
int		error(void);
int		check_saving(const char **stack, t_stack **stack_a);
void	free_stack(t_stack *stack);
t_stack	*stacklast(t_stack *stack);
t_stack	*stack_penultimate(t_stack *stack);
void	stackadd_top(t_stack **stack, t_stack *element);
void	stackadd_bottom(t_stack **stack, t_stack *element);
t_stack	*stacknew(int num);
int		is_ascending(t_stack *a);
#endif
