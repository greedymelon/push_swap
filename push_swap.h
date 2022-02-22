/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:38 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/22 20:26:51 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./libft/libft.h" 
# include <unistd.h>
# include <stdlib.h>

typedef enum e_parameter{
	NOPARAMETER = 1,
	FALSE = 0,
}	t_paramiter;

typedef struct s_stack{
	int		number;
	struct s_stack	next;
}	t_stack;

int		is_valid_input(char **stack);
int		error(void);
void	save_stack(char **stack, t_stack **stack_a);
t_stack	*stacklast(t_list *stack);
void	stackadd_front(t_stack **stack, t_stack *element);
void	stackadd_back(t_stack **stack, t_stack *element);
t_stack	*stacknew(int number);
t_stack	*push_stack(t_stack **stack_sender, t_stack **stack_target);
void	rv_rotate_stack(t_stack **stack);
void	swap_first(t_stack **stack);
#endif
