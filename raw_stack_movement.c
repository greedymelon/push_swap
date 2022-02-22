t_stack	*push_stack(t_stack **stack_sender, t_stack **stack_target)
{
    t_stack	*first_element;

    first_element = *stack_sender;
    *stack_sender = stack_sender->next;
    stackadd_front(stack_target, first_element);
}

void	rotate_stack(t_stack **stack)
{
	stackadd_back(stack, *stack);
}

void	rv_rotate_stack(t_stack **stack)
{
	stackadd_front(stack, stacklast(*stack));
}

void	swap_first(t_stack **stack)
{
    t_stack	*place_holder;

    place_holder = *stack;
    *stack = stack->next;
    place_holder->next = stack->next;
    stack->next = place_holder;
}