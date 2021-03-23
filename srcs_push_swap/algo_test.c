#include "../includes/push_swap.h"
#include <stdio.h>

void	push_max_b_on_a(t_stack *stack)
{
	int	big;

	while (stack->size_b > 0)
	{
		big = find_biggest_b(stack);
		//printf("big %d -> %d\n", big, stack->b[big]);
		if (big > stack->size_b / 2)
		{
			while (big < stack->size_b)
			{
				which_action("rrb", stack);
				big++;
			}
		}
		else
		{
			while (big > 0)
			{
				which_action("rb", stack);
				big--;
			}
		}
		which_action("pa", stack);
	}
}

void	set_last_push(t_stack *stack, int last_push)
{
	int	i;

	i = 0;
	while (i < stack->size_a && stack->a[i] != last_push)
		i++;
	printf("i : %d\n", i);
	if (i >= stack->size_a / 2)
	{
		while (i < stack->size_a)
		{
			which_action("rra", stack);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			which_action("ra", stack);
			i--;
		}
	}

}

void	test_sort(t_stack *stack)
{
	//printf("median : %d\n", stack->median);
	int	half;
	int	quarter;
	int	quarter3;
	int	last_push;

	half = stack->size_a - (stack->size_a / 2);
	quarter = stack->size_a / 4;
	quarter3 = stack->size_a - quarter;
	printf("half : %d\n", half);
	printf("quarter : %d quarter3 : %d size : %d stackquarter3 : %d stackquarter : %d median : %d\n", \
	quarter, quarter3, stack->size_a, stack->quarter3, stack->quarter, stack->median);
	while (stack->size_a > quarter3)
	{
		if (stack->a[0] > stack->quarter3)
			which_action("pb", stack);
		else
			which_action("ra", stack);
	}
	//printf("stack size %d  %d\n", stack->size_a, stack->size_a - (stack->size_a / 2));
	afficher_piles(stack);
	push_max_b_on_a(stack);
	printf("size %% 4 : %d\n", stack->size_a % 4);
	if (stack->size_a % 4 == 3)
		quarter3--;
	last_push = stack->a[0];
	afficher_piles(stack);
	//printf("half : %d median : %d\n", half, stack->median);
	while (stack->size_a > quarter3)
	{
		if (stack->a[0] <= stack->quarter3 && stack->a[0] > stack->median)
			which_action("pb", stack);
		else
			which_action("rra", stack);
	}
	afficher_piles(stack);
	set_last_push(stack, last_push);
	afficher_piles(stack);
	push_max_b_on_a(stack);
	afficher_piles(stack);
}