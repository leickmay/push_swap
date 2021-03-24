/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huge_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:26:48 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 15:53:14 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	set_last_push(t_stack *stack, int last_push)
{
	int	i;

	i = 0;
	while (i < stack->size_a && stack->a[i] != last_push)
		i++;
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

int	quarter_two(t_stack *stack, int quarter)
{
	int	i;
	int	last_push;

	i = 0;
	if (stack->size_a % 4 == 3)
		quarter += 2;
	if (stack->size_a % 4 == 2 || stack->size_a % 4 == 1)
		quarter++;
	last_push = stack->a[0];
	while (i < quarter)
	{
		if (stack->a[0] < stack->quarter3 && stack->a[0] >= stack->median)
		{
			which_action("pb", stack);
			i++;
		}
		else
			which_action("ra", stack);
	}
	set_last_push(stack, last_push);
	push_max_b_on_a(stack);
	return (quarter);
}

int	quarter_three(t_stack *stack, int quarter)
{
	int	i;
	int	last_push;

	i = 0;
	if (stack->size_a % 2 == 1)
		quarter--;
	last_push = stack->a[0];
	i = 0;
	while (i < quarter)
	{
		if (stack->a[0] < stack->median && stack->a[0] >= stack->quarter)
		{
			which_action("pb", stack);
			i++;
		}
		else
			which_action("rra", stack);
	}
	set_last_push(stack, last_push);
	push_max_b_on_a(stack);
	return (quarter);
}

void	quarter_four(t_stack *stack, int quarter)
{
	int	i;
	int	last_push;

	i = 0;
	if (stack->size_a % 4 == 3 || stack->size_a % 4 == 2)
		quarter--;
	last_push = stack->a[0];
	while (i < quarter)
	{
		if (stack->a[0] < stack->quarter)
		{
			which_action("pb", stack);
			i++;
		}
		else
			which_action("rra", stack);
	}
	set_last_push(stack, last_push);
	push_max_b_on_a(stack);
}

void	huge_sort(t_stack *stack)
{
	int	quarter;
	int	i;

	quarter = stack->size_a / 4;
	i = 0;
	while (i < quarter)
	{
		if (stack->a[0] >= stack->quarter3)
		{
			which_action("pb", stack);
			i++;
		}
		else
			which_action("ra", stack);
	}
	push_max_b_on_a(stack);
	quarter = quarter_two(stack, quarter);
	quarter = quarter_three(stack, quarter);
	quarter_four(stack, quarter);
}
