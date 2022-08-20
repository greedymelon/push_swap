/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   stack_ordering.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 12:34:01 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 12:34:03 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack *a)
{
	while (a)
	{
		a->idx = -1;
		a = a->next;
	}
}

t_stack	*min_int(t_stack *a)
{
	t_stack	*min;

	min = NULL;
	while (a)
	{
		if (a->idx == -1 && min == NULL)
			min = a;
		if (min != NULL && min->num > a->num && a->idx == -1)
			min = a;
		a = a->next;
	}
	return (min);
}

void	assign_index(t_stack *a)
{
	int	i;
	int	len;

	i = 0;
	len = stack_count(a);
	set_index(a);
	while (i < len)
	{
		min_int(a)->idx = i;
		i++;
	}
}
