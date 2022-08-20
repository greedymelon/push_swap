/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_mv_print.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 12:31:50 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 12:32:38 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	compute_move(int move, t_stack **a, t_stack **b)
{
	print_move(move);
	if (move == sa || move == ss)
		swap(a);
	if (move == sb || move == ss)
		swap(b);
	if (move == pa)
		push(b, a);
	if (move == pb)
		push(a, b);
	if (move == ra || move == rr)
		rotate(a);
	if (move == rb || move == rr)
		rotate(b);
	if (move == rra || move == rrr)
		rv_rotate(a);
	if (move == rrb || move == rrr)
		rv_rotate(b);
}

void	print_move(int move)
{
	if (move == sa)
		ft_printf("sa\n");
	if (move == sb)
		ft_printf("sb\n");
	if (move == ss)
		ft_printf("ss\n");
	if (move == pa)
		ft_printf("pa\n");
	if (move == pb)
		ft_printf("pb\n");
	if (move == ra)
		ft_printf("ra\n");
	if (move == rb)
		ft_printf("rb\n");
	if (move == rr)
		ft_printf("rr\n");
	if (move == rra)
		ft_printf("rra\n");
	if (move == rrb)
		ft_printf("rrb\n");
	if (move == rrr)
		ft_printf("rrr\n");
}

int	stack_count(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{	
		stack = stack->next;
		count++;
	}
	return (count);
}

int	is_ascending(t_stack *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}
