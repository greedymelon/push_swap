/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:31:49 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/17 15:58:46 by dmonfrin      ########   odam.nl         */
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

void	solve_puzzle (t_stack **a, int numb_element)
{
	t_stack *b;

	b = NULL;
	if (is_ascending(*a))
		return ;
	if (numb_element <= 3)
		three_algo(a, &b);
	if (numb_element <= 5)
		five_algo(a, &b);
	if (numb_element > 5)
		undred_algo(a, &b);
	free_stack(&b);
	return(1);
}

void three_algo(t_stack **a, t_stack **b)
{
	if (((*a)->nb > (*a)->next->nb) && ((*a)->nb < (*a)->next->next->nb))
		compute_move(pa, a, &b);
	if (((*a)->nb < (*a)->next->nb) && ((*a)->nb > (*a)->next->next->nb))
		compute_move(ra, a, &b);
}