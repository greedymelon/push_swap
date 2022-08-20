/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_stack_creation.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 14:37:46 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 14:37:47 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stacknew(int num)
{
	t_stack	*new_element;

	new_element = malloc(sizeof(t_stack));
	if (new_element == NULL)
		return (NULL);
	new_element->num = num;
	new_element->next = NULL;
	return (new_element);
}

void	stackadd_bottom(t_stack **stack, t_stack *element)
{
	if (*stack == NULL)
		*stack = element;
	else
	{
		if (*stack == element && (*stack)->next != NULL )
		{
			*stack = (*stack)->next;
			element->next = NULL;
		}
		if (*stack != element)
			stacklast(*stack)->next = element;
	}
}

void	stackadd_top(t_stack **stack, t_stack *element)
{
	element->next = *stack;
	*stack = element;
}

t_stack	*stacklast(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

t_stack	*stack_penultimate(t_stack *stack)
{
	if (stack == NULL)
		return (stack);
	while (stack->next != NULL && stack->next->next != NULL)
		stack = stack->next;
	return (stack);
}
