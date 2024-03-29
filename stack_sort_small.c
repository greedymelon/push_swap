/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_sort_small.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:31:49 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 12:34:34 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_algo(t_stack **a, t_stack **b)
{
	if (((*a)->num > (*a)->next->num) && ((*a)->num > (*a)->next->next->num))
		compute_move(ra, a, b);
	if (((*a)->num > (*a)->next->num) && ((*a)->num < (*a)->next->next->num))
		compute_move(sa, a, b);
	if (((*a)->num < (*a)->next->num) && ((*a)->num > (*a)->next->next->num))
		compute_move(rra, a, b);
	if (((*a)->next->num > (*a)->next->next->num))
	{
		compute_move(ra, a, b);
		compute_move(sa, a, b);
		compute_move(rra, a, b);
	}	
}

int	smalest_numb(t_stack *a)
{
	int	smalest_n;

	smalest_n = a->num;
	a = a->next;
	while (a->next)
	{
		if (smalest_n > a->num)
			smalest_n = a->num;
		a = a->next;
	}
	if (smalest_n > a->num)
		smalest_n = a->num;
	return (smalest_n);
}

int	pos_smal_numb(t_stack *a, int num)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->num == num)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}

void	push_smalest(t_stack **a, t_stack **b)
{
	int	pos_snum;

	pos_snum = pos_smal_numb(*a, smalest_numb(*a));
	if (pos_snum <= stack_count(*a) / 2)
	{
		while (pos_snum)
		{
			compute_move(ra, a, b);
			pos_snum--;
		}
	}
	else
	{
		pos_snum = stack_count(*a) - pos_snum;
		while (pos_snum)
		{
			compute_move(rra, a, b);
			pos_snum--;
		}
	}
	compute_move(pb, a, b);
}

void	five_algo(t_stack **a, t_stack **b)
{
	push_smalest(a, b);
	if (stack_count(*a) > 3)
		push_smalest(a, b);
	three_algo(a, b);
	compute_move(pa, a, b);
	if (*b)
		compute_move(pa, a, b);
}
