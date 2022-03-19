/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/03/19 18:46:33 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc == NOPARAMETER)
		return (1);
	if (!is_valid_input(&argv[1]))
		return (error());
	if (save_stack(&argv[1], &a))
		return (error());
	solve_puzzle(&a, argc - 1);
	free_stack(&a);
	return (0);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
