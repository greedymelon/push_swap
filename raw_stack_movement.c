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
	if ((*stack_sender)->next ==  NULL)
		(*stack_sender) == NULL;
	else
		(*stack_sender) = (*stack_sender)->next;
	stackadd_top(stack_target, first_element);
}
//check the logit
void	rotate(t_stack **stack)
{
	t_stack	*first_element;

	first_element = *stack;
	(*stack) = (*stack)->next;
	first_element->next = NULL;
	
}
 

void	rv_rotate(t_stack **stack)
{
	t_stack	*first_element;
	t_stack	*last_element;

	last_element = stacklast(*stack);
	last_element->next = (*stack)->next;
	first_element = *stack;
	(*stack) = last_element;
	first_element->next = NULL;
	stack_penultimate(*stack)->next = first_element;
}

void	swap(t_stack **stack)
{
	t_stack	*place_holder;

	place_holder = *stack;
	*stack = (*stack)->next;
	place_holder->next = (*stack)->next;
	(*stack)->next = place_holder;
}
