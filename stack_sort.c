/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:31:49 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/03/19 17:47:26 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int is_ascending (t_stack a)
{
	while (a.next != NULL)
	{
		if (a.number > a.next.number)
			return (0);
		a.next = a.next.next;
	}
	return (1);
}

int solve_puzzle (t_stack **a, int stack_element)
{
    t_stack *b;

	if (is_ascending(**a))
		return (1);
	if (stack_element <= 5)

	if (stack_element < 500)
	
	

    
}

void print_and_move(t_stack *stack_a, t_stack *stack_b, char *move)
{
	ft_printf ("%s\n", move);
}


void print_and_move(t_stack **a, t_stack **b)
{
	if (**a && (*a)->next && ((*a)->number < (*a)->next->number))
	{
		if (**b && (*b)->next && ((*b)->number > (*b)->next->number))
			compute_move(ss);
		else
			compute_move(sa);		
	}
	if (**b && (*b)->next && ((*b)->number > (*b)->next->number))
		compute_move(sb);
	if (**a && (*a)->next) && ((*a)->number > stacklast(*a)->number))
	{
		if (**b && (*b)->next && ((*b)->number < stacklast(*b)->number))
			compute_move(rr);
		else
			compute_move(ra);		
	}
	if (**b && (*b)->next && ((*b)->number < stacklast(*b)->number))
		compute_move(rrb);