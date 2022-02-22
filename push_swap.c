/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/22 20:31:55 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;

	if (argc == NOPARAMETER)
		return (1);
	if (!is_valid_input(&argv[1]))
		return (error());
	save_stack(&argv[1], stack_a);
	solve_puzzle(stack_a);
	return (0);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
