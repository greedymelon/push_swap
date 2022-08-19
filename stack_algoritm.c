#include "push_swap.h"


void	bitwise_stack(t_stack **a, t_stack **b, int position)
{
	t_stack	*place_holder;
	int	i;

	i = 0;
	place_holder = *a;
	while (place_holder)
	{
		if (((place_holder->idx >> position) & 1) == 0)
		{
			while (i)
			{
				compute_move(rra, a, b);
				i--;
			}
			compute_move(pb, a, b);
		}
		place_holder = place_holder->next;
		i++;
	}
	place_holder = *b;
	i = 0;
	while (place_holder)
	{
		if ((((place_holder->idx >> position)) & 1) == 1)
		{
			while (i)
			{
				compute_move(rrb, a, b);
				i--;
			}
			compute_move(pa, a, b);
		}
		place_holder = place_holder->next;
		i++;
	}
}

void	stack_ping_pong(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while(i < 31)
	{
		bitwise_stack(a, b, i);
		i++;
	}
	while(*b)
	{
		compute_move(pa, a, b);
	}
}

void	radix(t_stack **a, t_stack **b)
{
	if (!b) 
	set_index(*a);
	assign_index(*a);
	stack_ping_pong(a,b);
	print_idx(*a);


}

// 1 << 1 = 2

// 1 & 2 = 1
// 2 & 1 = 0
// 3 & 1 = 1


// 0001 1
// 		0010 2
// 0011 3
// 		0100 4
// 0101 5
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", 1 << 31); //
// 	// printf("%d\n", 1 << 1); // 0001 << 1 = 0010
// 	// printf("%d", 1 >> 1);
// 	// printf("%d", 1 >> 1);
// 	// printf("%d", 1 >> 1);
// 	// printf("%d", 1 >> 1);
// 	// if ((struct.value >> i) & 1) == 0
// 	// {
// 	// 	push to b
// 	// 	i++;
// 	// }

// 	// (struct.value & i) == 0
// 	// {
// 	// 	i * 2
// 	// }
	
// }