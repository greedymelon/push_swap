/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_input.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 14:37:05 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 14:37:09 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	error(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (0);
}

int	is_string_of_string(const char *stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	str_of_str(const char *stack, t_stack **stack_a)
{	
	int		i;
	char	**divided_stack;

	divided_stack = ft_split(stack, ' ');
	if (!divided_stack)
		return (0);
	i = 0;
	while (divided_stack[i])
	{
		if (!is_valid_input(divided_stack[i]))
		{
			ft_free_mem(divided_stack, ft_strslen(divided_stack));
			return (0);
		}
		stackadd_bottom(stack_a, stacknew(ft_atoi(divided_stack[i])));
		i++;
	}
	ft_free_mem(divided_stack, ft_strslen(divided_stack));
	return (1);
}

int	check_saving(const char **stack, t_stack **stack_a)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (is_string_of_string(stack[i]))
		{
			if (!str_of_str(stack[i], stack_a))
				return (0);
		}
		else
		{
			if (!is_valid_input(stack[i]))
				return (0);
			stackadd_bottom(stack_a, stacknew(ft_atoi(stack[i])));
		}
		i++;
	}
	if (!is_duplicate(*stack_a))
		return (0);
	return (1);
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
