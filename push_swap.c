/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 12:30:15 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, const char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc == NOPARAMETER)
		return (1);
	if (!check_saving(&argv[1], &a))
	{	
		free_stack(a);
		return (1);
	}
	solve_puzzle(&a, stack_count(a));
	free_stack(a);
	return (0);
}

int	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}

void	solve_puzzle(t_stack **a, int numb_element)
{
	t_stack	*b;

	b = NULL;
	if (is_ascending(*a))
		return ;
	if (numb_element == 2)
		compute_move(sa, a, &b);
	else if (numb_element == 3)
		three_algo(a, &b);
	else if (numb_element <= 5)
		five_algo(a, &b);
	else
		radix(a, &b);
	free_stack(b);
}
