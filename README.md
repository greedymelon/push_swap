# **push_swap**
School project 4

## *Description*
The aim of the program is to sort a stack of numbers with a second stack with a limited set of movement:
```
sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time.
```

First, it checks that the input given is a list of integer without duplicate.
Then sort the stack and print the move necessary to sort it.
There are two different implementations to solve it: <br>
if the list size is smaller or equal to 5 it uses hardcoded interaction;<br>
if the stack has more than 5 elements it uses radix sort.

## *How to get started*
Run the ```make``` command to compile the program, and then run it with a list of numbers, for es:
```./push_swap 3 2 1```
