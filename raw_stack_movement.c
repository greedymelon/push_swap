// #include "push_swap.h"

// t_stack	*push(t_stack **stack_sender, t_stack **stack_target)
// {
//     t_stack	*first_element;

//     first_element = *stack_sender;
//     *stack_sender = stack_sender->next;
//     stackadd_front(stack_target, first_element);
// }

// void	rotate(t_stack **stack)
// {
// 	stackadd_back(stack, *stack);
// }

// void	rv_rotate(t_stack **stack)
// {
// 	stackadd_front(stack, stacklast(*stack));
// }

// void	swap(t_stack **stack)
// {
//     t_stack	*place_holder;

//     place_holder = *stack;
//     *stack = stack->next;
//     place_holder->next = stack->next;
//     stack->next = place_holder;
// }