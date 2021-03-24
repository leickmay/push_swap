/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:15:26 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 16:30:36 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_slot_max_else(t_stack *stack, t_pos_b *pos)
{
	while (pos->closest_pos > 0)
	{
		which_action("rb", stack);
		pos->closest_pos--;
	}
	if (stack->a[0] < pos->closest_value)
	{
		which_action("rb", stack);
		pos->closest_pos = stack->size_b - 1;
	}
}

void	find_slot_max(t_stack *stack)
{
	t_pos_b	pos;
	int		middle;

	middle = stack->size_b - (stack->size_b / 2);
	init_t_pos_b(stack, &pos);
	if (pos.closest_pos >= middle)
	{
		while (pos.closest_pos < stack->size_b - 1)
		{
			which_action("rrb", stack);
			pos.closest_pos++;
		}
		if (stack->a[0] > pos.closest_value)
		{
			which_action("rrb", stack);
			pos.closest_pos = 0;
		}
	}
	else
		find_slot_max_else(stack, &pos);
}

void	push_min(t_stack *stack, t_pos *pos)
{
	if (pos->min_dist_bottom > pos->min_pos)
	{
		while (pos->min_pos > 0)
		{
			which_action("ra", stack);
			pos->min_pos--;
		}
	}
	else
	{
		while (pos->min_dist_bottom > 0)
		{
			which_action("rra", stack);
			pos->min_dist_bottom--;
		}
	}
	if (stack->size_b > 1)
		find_slot_max(stack);
	which_action("pb", stack);
}

void	push_max(t_stack *stack, t_pos *pos)
{
	if (pos->max_dist_bottom > pos->max_pos)
	{
		while (pos->max_pos > 0)
		{
			which_action("ra", stack);
			pos->max_pos--;
		}
	}
	else
	{
		while (pos->max_dist_bottom > 0)
		{
			which_action("rra", stack);
			pos->max_dist_bottom--;
		}
	}
	if (stack->size_b > 1)
		find_slot_max(stack);
	which_action("pb", stack);
}

void	min_max_algo(t_stack *stack)
{
	t_pos	pos;

	while (stack->size_a > 0)
	{
		init_t_pos_a(stack, &pos);
		if (pos.max_closest > pos.min_closest)
			push_min(stack, &pos);
		else
			push_max(stack, &pos);
	}
	while (stack->size_b > 0)
		which_action("pa", stack);
	init_t_pos_a(stack, &pos);
	push_values_end(stack, &pos);
}
