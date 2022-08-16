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

void	push(t_stack **stack_sender, t_stack **stack_target)
{
	t_stack	*first_element;

	first_element = *stack_sender;
	(*stack_sender) = (*stack_sender)->next;
	stackadd_top(stack_target, first_element);
}

void	rotate(t_stack **stack)
{
	stackadd_bottom(stack, *stack);
}

void	rv_rotate(t_stack **stack)
{
	stackadd_top(stack, stacklast(*stack));
}

void	swap(t_stack **stack)
{
	t_stack	*place_holder;

	place_holder = *stack;
	*stack = (*stack)->next;
	place_holder->next = (*stack)->next;
	(*stack)->next = place_holder;
}
