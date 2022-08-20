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
