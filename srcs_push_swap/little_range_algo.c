/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_range_algo.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:44:53 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/20 14:56:49 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	three_sort_algo(t_stack *stack)
{
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			which_action("sa", stack);
	}
	if (stack->size_a == 3)
	{
		while (check_sorted_a(stack) == 0)
		{
			if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
				which_action("ra", stack);
			if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
				which_action("sa", stack);
			if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2] && \
			stack->a[0] > stack->a[2])
				which_action("sa", stack);
			if (stack->a[0] < stack->a[1] && stack->a[2] < stack->a[1] && \
			stack->a[2] < stack->a[0])
				which_action("rra", stack);
			if (stack->a[0] < stack->a[1] && stack->a[2] < stack->a[1] && \
			stack->a[2] > stack->a[0])
				which_action("ra", stack);
			check_sorted_a(stack);
		}
	}
}

void	three_sort_algo_b(t_stack *stack)
{
	if (stack->size_b == 2)
	{
		if (stack->b[0] > stack->b[1])
			which_action("sb", stack);
	}
	if (stack->size_b == 3)
	{
		while (check_sorted_b_reversed(stack) == 0)
		{
			if (stack->b[0] < stack->b[1] && stack->b[0] < stack->b[2] && \
			stack->b[1] > stack->b[2])
				which_action("rb", stack);
			if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2] && \
			stack->b[0] < stack->b[2])
				which_action("rrb", stack);
			if (stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2] && \
			stack->b[0] > stack->b[2])
				which_action("sb", stack);
			if (stack->b[0] < stack->b[1] && stack->b[0] < stack->b[2] && \
			stack->b[1] < stack->b[2])
				which_action("sb", stack);
			check_sorted_b_reversed(stack);
		}
	}
}

void	push_smallest_b(t_stack *stack, int smallest)
{
	int	middle;
	int	i;

	middle = stack->size_a / 2;
	if (smallest > middle)
	{
		i = 0;
		while (i < stack->size_a - smallest)
		{
			which_action("rra", stack);
			i++;
		}
	}
	else
	{
		i = smallest;
		while (i > 0)
		{
			which_action("ra", stack);
			i--;
		}
	}
	which_action("pb", stack);
}

void	six_sort_algo(t_stack *stack)
{
	int	smallest;

	smallest = find_smallest(stack);
	push_smallest_b(stack, smallest);
	smallest = find_smallest(stack);
	push_smallest_b(stack, smallest);
	if (stack->size_a == 4)
	{
		smallest = find_smallest(stack);
		push_smallest_b(stack, smallest);
		three_sort_algo(stack);
		three_sort_algo_b(stack);
		which_action("pa", stack);
		which_action("pa", stack);
		which_action("pa", stack);
	}
	if (stack->size_b == 2)
	{
		three_sort_algo(stack);
		two_reverse_sort_b(stack);
		which_action("pa", stack);
		which_action("pa", stack);
	}
}

void	two_reverse_sort_b(t_stack *stack)
{
	if (stack->size_b == 2)
	{
		if (stack->b[0] < stack->b[1])
			which_action("sb", stack);
	}
}
