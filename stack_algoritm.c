#include "push_swap.h"

void	move_stack_a(t_stack **a, t_stack **b, int position)
{
	t_stack	*place_holder;
	int	i;
	int	move_back;

	i = 0;
	move_back = 0;
	place_holder = *a;
	//print_idx(*a);
	while (place_holder)
	{
		if (((place_holder->idx >> position) & 1) == 0)
		{
			while (i)
			{
				compute_move(ra, a, b);
				i--;
				move_back++;
			}
			compute_move(pb, a, b);
			place_holder = *a;
		}
		else
		{	
			place_holder = place_holder->next;
			i++;
		}
	}
	//ft_printf("A pos %d compute %d  stack %d \n",position, move_back, stack_count(*a));
	//print_idx(*a);
	if (stack_count(*a) <= 1)
		return ;
	if (move_back < stack_count(*a)/2)
		while (move_back--)
			compute_move(rra, a, b);
	else
	{
		move_back = stack_count(*a) - move_back;
		while (move_back--)
			compute_move(ra, a, b);
	}
	//print_idx(*a);
}

void	move_stack_b(t_stack **a, t_stack **b, int position)
{
	t_stack	*place_holder;
	int	i;
	int	move_back;

	
	place_holder = *b;
	i = 0;
	move_back = 0;
	while (place_holder)
	{
		if ((((place_holder->idx >> position)) & 1) == 1)
		{
			while (i)
			{
				compute_move(rb, a, b);
				i--;
				move_back++;
			}
			compute_move(pa, a, b);
			place_holder = *b;
		}
		else
		{	
			place_holder = place_holder->next;
			i++;
		}
	}

	//ft_printf("B pos %d compute %d  stack %d \n",position, move_back, stack_count(*b));
	//print_idx(*b);
	if (stack_count(*b) <= 1)
		return ;
	if (move_back < stack_count(*b)/2)
		while (move_back--)
			compute_move(rrb, a, b);
	else
	{
		move_back =  stack_count(*b) - move_back;
		while (move_back--)	
			compute_move(rb, a, b);
	}
	//print_idx(*b);
}

void	stack_ping_pong(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	while(i < 31)
	{
		move_stack_b(a, b, i);
		move_stack_a(a, b, i);
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
	//print_idx(*a);


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