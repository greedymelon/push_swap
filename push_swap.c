/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/18 11:53:49 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack *a)
{	
	while(a)
	{
		ft_printf("*%d", a->num);
		a = a->next;
	}
	ft_printf("\n");
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
	//test_move(&a);
	solve_puzzle(&a, stack_count(a));
	print_stack (a);
	
	free_stack(a);
	return (0);
}

int	error(void)
{
	write(2, "Error\n", 6);
	return (1);
}
