/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:42:45 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 16:30:41 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_values_end(t_stack *stack, t_pos *pos)
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

void	push_max_b_on_a(t_stack *stack)
{
	int	big;

	while (stack->size_b > 0)
	{
		big = find_biggest_b(stack);
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

void	init_t_pos_a(t_stack *stack, t_pos *pos)
{
	pos->max_pos = find_biggest(stack);
	pos->max_value = stack->a[pos->max_pos];
	pos->max_dist_bottom = stack->size_a - pos->max_pos;
	if (pos->max_dist_bottom > pos->max_pos)
		pos->max_closest = pos->max_pos;
	else
		pos->max_closest = pos->max_dist_bottom;
	pos->min_pos = find_smallest(stack);
	pos->min_value = stack->a[pos->min_pos];
	pos->min_dist_bottom = stack->size_a - pos->min_pos;
	if (pos->min_dist_bottom > pos->min_pos)
		pos->min_closest = pos->min_pos;
	else
		pos->min_closest = pos->min_dist_bottom;
}

void	find_closest_value(t_stack *stack, t_pos_b *pos)
{
	int	i;
	int	diff;
	int	diff2;

	i = 0;
	diff2 = stack->a[0] - stack->b[i];
	pos->closest_pos = 0;
	while (i < stack->size_b)
	{
		diff = stack->a[0] - stack->b[i];
		if (diff < 0)
			diff *= -1;
		if (diff <= diff2)
		{
			diff2 = diff;
			pos->closest_pos = i;
		}
		i++;
	}
	pos->closest_value = stack->b[pos->closest_pos];
}

void	init_t_pos_b(t_stack *stack, t_pos_b *pos)
{
	pos->max_pos = find_biggest_b(stack);
	pos->max_value = stack->b[pos->max_pos];
	pos->max_dist_bottom = stack->size_b - pos->max_pos;
	if (pos->max_dist_bottom > pos->max_pos)
		pos->max_closest = pos->max_pos;
	else
		pos->max_closest = pos->max_dist_bottom;
	pos->min_pos = find_smallest_b(stack);
	pos->min_value = stack->b[pos->min_pos];
	pos->min_dist_bottom = stack->size_b - pos->min_pos;
	if (pos->min_dist_bottom > pos->min_pos)
		pos->min_closest = pos->min_pos;
	else
		pos->min_closest = pos->min_dist_bottom;
	find_closest_value(stack, pos);
}
