/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_move.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 14:37:24 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 14:40:37 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	compute_move(int move, t_stack **a, t_stack **b)
{
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
