/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: dmonfrin <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 14:36:27 by dmonfrin      #+#    #+#                 */
/*   Updated: 2022/08/20 14:41:08 by dmonfrin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, const char **argv)
{
	t_stack	*a;

	a = NULL;
	if (argc == NOPARAMETER)
		return (1);
	if (!check_saving(&argv[1], &a))
	{	
		free_stack(a);
		return (1);
	}
	if (is_sorted(&a))
		return (1);
	free_stack(a);
	return (0);
}

int	is_ascending(t_stack *a)
{
	while (a->next)
	{
		if (a->num > a->next->num)
			return (0);
		a = a->next;
	}
	return (1);
}

int	is_sorted(t_stack **a)
{
	t_stack	*b;

	b = NULL;
	read_sort(a, &b);
	if (!is_ascending(*a) || b)
		return (error());
	ft_printf("OK\n");
	return (1);
}

void	read_sort(t_stack **a, t_stack **b)
{
	char	*move;

	move = get_next_line(STDIN_FILENO);
	while (move)
	{	
		if (ft_strncmp(move, "\n", 1) == 0)
			break ;
		process_move(move, a, b);
		free(move);
		move = get_next_line(STDIN_FILENO);
	}
	free (move);
}

void	process_move(char *move, t_stack **a, t_stack **b)
{
	int			i;
	const char	moves[12][3] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr"};

	i = 0;
	while (i < 12)
	{
		if (ft_strncmp(moves[i], move, 2) == 0)
		{
			compute_move(i, a, b);
			break ;
		}
		i++;
	}
}
