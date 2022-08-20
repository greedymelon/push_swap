/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_algoritm.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 12:33:34 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 12:37:40 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_stack_a(t_stack **a, t_stack **b, int position)
{
	t_stack	*place_holder;
	int		i;
	int		move_back;

	i = 0;
	move_back = 0;
	place_holder = *a;
	while (place_holder)
	{
		if (((place_holder->idx >> position) & 1) == 0)
		{
			move_ahead_a_push(&i, &move_back, a, b);
			place_holder = *a;
		}
		else
		{	
			place_holder = place_holder->next;
			i++;
		}
	}
	move_back_a(move_back, a, b);
}

void	move_stack_b(t_stack **a, t_stack **b, int position)
{
	t_stack	*place_holder;
	int		i;
	int		move_back;

	place_holder = *b;
	i = 0;
	move_back = 0;
	while (place_holder)
	{
		if ((((place_holder->idx >> position)) & 1) == 1)
		{
			move_ahead_b_push(&i, &move_back, a, b);
			place_holder = *b;
		}
		else
		{	
			place_holder = place_holder->next;
			i++;
		}
	}
	move_back_a(move_back, a, b);
}

void	stack_ping_pong(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while (i < 31)
	{
		move_stack_b(a, b, i);
		move_stack_a(a, b, i);
		i++;
	}
	while (*b)
		compute_move(pa, a, b);
}

void	radix(t_stack **a, t_stack **b)
{
	set_index(*a);
	assign_index(*a);
	stack_ping_pong(a, b);
}
