#include "push_swap.h"

void print_idx(t_stack *a)
{	
	while(a)
	{
		ft_printf("%d ", a->idx);
		a = a->next;
	}
	ft_printf("\n");
}

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
