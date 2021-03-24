/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max_improved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:19:12 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 15:44:29 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/*
void	find_slot_max_i(t_stack *stack)
{
	t_pos_b pos;
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
	{
		while (pos.closest_pos > 0)
		{
			which_action("rb", stack);
			pos.closest_pos--;
		}
		if (stack->a[0] < pos.closest_value)
		{
			which_action("rb", stack);
			pos.closest_pos = stack->size_b - 1;
		}
	}
}

void	push_min_i(t_stack *stack, t_pos *pos)
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
		find_slot_max_i(stack);
	which_action("pb", stack);
	stack->min++;
}

void	push_max_i(t_stack *stack, t_pos *pos)
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
		find_slot_max_i(stack);
	which_action("pb", stack);
}

void	push_values_end_i(t_stack *stack, t_pos *pos)
{
	if (pos->max_dist_bottom > pos->max_pos)
	{
		while (pos->max_pos >= 0)
		{
			which_action("ra", stack);
			pos->max_pos--;
		}
	}
	else
	{
		while (pos->max_dist_bottom > 1)
		{
			which_action("rra", stack);
			pos->max_dist_bottom--;
		}
	}
}

void	init_t_pos_a_big(t_stack *stack,t_pos *pos)
{
	pos->max_pos = find_biggest(stack);
	pos->max_value = stack->a[pos->max_pos];
	pos->max_dist_bottom = stack->size_a - pos->max_pos;
	if (pos->max_dist_bottom > pos->max_pos)
		pos->max_closest = pos->max_pos;
	else
		pos->max_closest = pos->max_dist_bottom;
	pos->min_pos = stack->min;
	pos->min_value = stack->a[pos->min_pos];
	pos->min_dist_bottom = stack->size_a - pos->min_pos;
	if (pos->min_dist_bottom > pos->min_pos)
		pos->min_closest = pos->min_pos;
	else
		pos->min_closest = pos->min_dist_bottom;
}


void	min_max_algo_i(t_stack *stack)
{
	t_pos	pos;

	stack->min = stack->median;
	while (stack->size_a > (stack->size_a - stack->size_a / 2))
	{
		init_t_pos_a_big(stack, &pos);
		if (pos.max_closest > pos.min_closest)
			push_min_i(stack, &pos);
		else
			push_max_i(stack, &pos);
	}
	while (stack->size_b > 0)
		which_action("pa", stack);
	init_t_pos_a(stack, &pos);
	push_values_end_i(stack, &pos);
}*/