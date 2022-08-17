/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/17 14:50:00 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *a)
{
	while(a->next)
	{
		ft_printf("%d", a->number);
		a = a->next;
	}
	ft_printf("%d", a->number);
}

int	main(int argc,const char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc == NOPARAMETER)
		return (1);
	if (!check_saving(&argv[1], &a))
	{	
		free_stack(a);
		return (error());
	}
	//
	test_move(&a);
	print_stack (a);
	//solve_puzzle(&a, argc - 1);
	free_stack(a);
	return (0);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
