/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:19:20 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/21 20:14:38 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	stack_a;

	if (argc == NOPARAMETER)
		return (1);
	if (!is_valid_input(&argv[1]))
		return (error());
	stack_a = malloc(argc - 1 * sizeof(int));
	save_stack(&argv[1], stack_a);
	free (stack_a);
}

int	error(void)
{
	write(2, "Error", 5);
	return (1);
}
