/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   giga_huge_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 14:43:48 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 15:51:58 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	decile_sort(t_stack *stack, int decile, int p_decile)
{
	int	i;
	int	to_sort;
	int	last_push;

	last_push = stack->a[0];
	to_sort = stack->size_a / 10;
	i = 0;
	while (i < to_sort)
	{
		if (stack->a[0] >= decile && stack->a[0] < p_decile)
		{
			which_action("pb", stack);
			i++;
		}
		else
			which_action("ra", stack);
	}
	set_last_push(stack, last_push);
	push_max_b_on_a(stack);
}

void	decile_sort_r(t_stack *stack, int decile, int p_decile)
{
	int	i;
	int	to_sort;
	int	last_push;

	last_push = stack->a[0];
	to_sort = stack->size_a / 10;
	i = 0;
	while (i < to_sort)
	{
		if (stack->a[0] >= decile && stack->a[0] < p_decile)
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

void	last_decile(t_stack *stack)
{
	int	i;
	int	to_sort;
	int	last_push;

	last_push = stack->a[0];
	to_sort = stack->size_a / 10 - 1;
	i = 0;
	while (i < to_sort)
	{
		if (stack->a[0] < stack->decile1)
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

void	giga_decile_sort(t_stack *stack)
{
	decile_sort(stack, stack->decile9, stack->decile10);
	decile_sort(stack, stack->decile8, stack->decile9);
	decile_sort(stack, stack->decile7, stack->decile8);
	decile_sort(stack, stack->decile6, stack->decile7);
	decile_sort(stack, stack->decile5, stack->decile6);
	decile_sort_r(stack, stack->decile4, stack->decile5);
	decile_sort_r(stack, stack->decile3, stack->decile4);
	decile_sort_r(stack, stack->decile2, stack->decile3);
	decile_sort_r(stack, stack->decile1, stack->decile2);
	last_decile(stack);
}

void	giga_huge_sort(t_stack *stack)
{
	int	to_sort;
	int	i;

	to_sort = stack->size_a - (stack->size_a / 10 * 10) + 1;
	i = 0;
	while (i < to_sort)
	{
		if (stack->a[0] >= stack->decile10)
		{
			which_action("pb", stack);
			i++;
		}
		else
			which_action("ra", stack);
	}
	push_max_b_on_a(stack);
	to_sort = stack->size_a / 10;
	giga_decile_sort(stack);
}
