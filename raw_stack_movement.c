/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   raw_stack_movement.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:27:42 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/25 13:27:48 by dmonfrin      ########   odam.nl         */
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

void	push(t_stack **stack_sender, t_stack **stack_target)
{
	t_stack	*first_element;

	if (!*stack_sender)
		return ;
	first_element = *stack_sender;
	if ((*stack_sender)->next == NULL)
		*stack_sender = NULL;
	else
		(*stack_sender) = (*stack_sender)->next;
	stackadd_top(stack_target, first_element);
}

void	rotate(t_stack **stack)
{
	t_stack	*first_element;

	if (!*stack || !(*stack)->next)
		return ;
	first_element = *stack;
	(*stack) = (*stack)->next;
	first_element->next = NULL;
	stackadd_bottom(stack, first_element);
}

void	rv_rotate(t_stack **stack)
{

	t_stack	*last_element;

	if (!*stack || !(*stack)->next)
		return ;
	last_element = stacklast(*stack);
	stack_penultimate(*stack)->next = NULL;
	last_element->next = (*stack);
	*stack = last_element;
}

void	swap(t_stack **stack)
{
	t_stack	*place_holder;

	if (!*stack)
		return ;
	place_holder = *stack;
	*stack = (*stack)->next;
	place_holder->next = (*stack)->next;
	(*stack)->next = place_holder;
}

void	print_move(int move)
{
	if (move == sa)
		ft_printf("sa\n");
	if (move == sb)
		ft_printf("sb\n");
	if (move== ss)
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
