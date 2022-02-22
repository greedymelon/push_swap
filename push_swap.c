/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/22 21:19:25 by anonymous     ########   odam.nl         */
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
	save_stack(&argv[1], &stack_a);
	t_stack *p_h = stack_a;
	while (p_h)
	{
		ft_printf("%d\n", p_h->number);
		p_h = p_h->next;
	}
	
	free_stack(&stack_a);
	//solve_puzzle(stack_a);
	return (0);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
