/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_saving_freeing.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/25 13:28:34 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/25 13:28:36 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	save_stack(char **stack, t_stack *stack_a)
{
	t_stack	*new_element;
	int		i;

	i = 0;
	*stack_a = NULL;
	while (stack[i])
	{
		new_element = stacknew(ft_atoi(stack[i]));
		if (new_element == NULL)
			return (2);
		stackadd_bottom(&stack_a, new_element);
		i++;
	}
	return (0);
}

void	free_stack(t_stack *stack)
{
	t_stack	*place_holder;
	t_stack	*index;


	if (stack != NULL)
	{
		place_holder = stack;
		index = stack;
		while (index != NULL)
		{
			index = index->next;
			free(place_holder);
			place_holder = index;
		}
	}
	stack = NULL;
}

