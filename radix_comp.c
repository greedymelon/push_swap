/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_comp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 12:32:59 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 12:39:43 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_ahead_a_push(int *n_move, int *store_m, t_stack **a, t_stack **b)
{
	while (*n_move)
	{
		compute_move(ra, a, b);
		(*n_move)--;
		(*store_m)++;
	}
	compute_move(pb, a, b);
}

void	move_back_a(int n_move, t_stack **a, t_stack **b)
{
	if (stack_count(*a) <= 1)
		return ;
	if (n_move < stack_count(*a) / 2)
		while (n_move--)
			compute_move(rra, a, b);
	else
	{
		n_move = stack_count(*a) - n_move;
		while (n_move--)
			compute_move(ra, a, b);
	}
}

void	move_ahead_b_push(int *n_move, int *store_m, t_stack **a, t_stack **b)
{
	while (*n_move)
	{
		compute_move(rb, a, b);
		(*n_move)--;
		(*store_m)++;
	}
	compute_move(pa, a, b);
}

void	move_back_b(int n_move, t_stack **a, t_stack **b)
{
	if (stack_count(*b) <= 1)
		return ;
	if (n_move < stack_count(*b) / 2)
		while (n_move--)
			compute_move(rrb, a, b);
	else
	{
		n_move = stack_count(*b) - n_move;
		while (n_move--)
			compute_move(rb, a, b);
	}
}
