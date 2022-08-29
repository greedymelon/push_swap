/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_stack_check.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:18:15 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 11:59:10 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_all_digit(const char *stack);
static int	is_all_integer(const char *stack);

int	is_valid_input(const char *stack)
{
	if (!is_all_digit(stack))
		return (error());
	if (!is_all_integer(stack))
		return (error());
	return (1);
}

static int	is_all_digit(const char *stack)
{
	int	i;

	i = 0;
	if ((stack[i] == '-' || stack[i] == '+') && stack[i])
		i++;
	while (stack[i])
	{
		if (!ft_isdigit(stack[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_all_integer(const char *stack)
{
	long int	num;

	if (ft_strlen(stack) > 11)
		return (0);
	num = ft_atoi_long(stack);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	return (1);
}

int	is_duplicate(t_stack *a)
{
	t_stack	*place_holder;

	if (!a || !a->next)
		return (0);
	while (a && a->next)
	{
		place_holder = a->next;
		while (place_holder)
		{	
			if (a->num == place_holder->num)
				return (error());
			place_holder = place_holder->next;
		}
		a = a->next;
	}
	return (1);
}
