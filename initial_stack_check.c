/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initial_stack_check.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/21 18:18:15 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/02/22 20:43:03 by anonymous     ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_all_digit(char **stack);
static int	is_duplicate(char **stack);
static int	is_all_integer(char **stack);

int	is_valid_input(char **stack)
{
	if (!is_all_digit(stack))
		return (0);
	if (duplicate(stack))
		return (0);
	if (!is_all_integer(stack))
		return (0);
	return (1);
}

static int	is_all_digit(char **stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (stack[i])
	{
		if (stack[i][j] == '-' && stack[i][j + 1])
			j++;
		while (stack[i][j])
		{
			if (!ft_isdigit(stack[i][j]))
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

static int	is_duplicate(char **stack)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (stack[i])
	{
		while (stack[j + i])
		{
			if (!ft_strncmp(stack[i], stack[j + i], 11))
				return (1);
			j++;
		}
		j = 1;
		i++;
	}
	return (0);
}

static int	is_all_integer(char **stack)
{
	int			i;
	long int	num;

	i = 0;
	while (stack[i])
	{
		if (ft_strlen(stack[i]) > 11)
			return (0);
		num = ft_atoi_long(stack[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}
