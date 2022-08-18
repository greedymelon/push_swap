#include "push_swap.h"
void	test_move (t_stack **a)
{
	t_stack	*b;
	b = NULL;
 	int i = 0;

	while(i < 10)
	{
		compute_move(pb, a, &b);
		i++;
	}
	i = 0;
	while (i < 11)
	{
		compute_move(i, a, &b);
		i++;
	}
}