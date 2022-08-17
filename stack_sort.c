/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:31:49 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/17 11:30:21 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending (t_stack *a)
{
	while (a->next)
	{
		if (a->number > a->next->number)
			return (0);
		a->next = a->next->next;
	}
	return (1);
}

int solve_puzzle (t_stack **a, int stack_element)
{
	t_stack *b;

	if (is_ascending(*a))
		return (1);
	if (stack_element <= 5)
	{}
	if (stack_element < 500)
	{}
	return(1);
}