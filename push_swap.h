/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:38 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/21 19:51:28 by dmonfrin      ########   odam.nl         */
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
void	save_stack(char **stack, int *stack_a);

#endif
