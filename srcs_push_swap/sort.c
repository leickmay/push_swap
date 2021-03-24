/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:17:57 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 16:02:31 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_smallest(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stack->size_a)
	{
		if (stack->a[i] > stack->a[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

int	find_biggest(t_stack *stack)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] > stack->a[big])
			big = i;
		i++;
	}
	return (big);
}

int	find_smallest_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stack->size_b)
	{
		if (stack->b[i] > stack->b[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

int	find_biggest_b(t_stack *stack)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] > stack->b[big])
			big = i;
		i++;
	}
	return (big);
}

void	sort_instructions(t_stack *stack)
{
	if (stack->size_a <= 3)
		three_sort_algo(stack);
	else if (stack->size_a <= 6 && stack->size_a > 3)
		six_sort_algo(stack);
	else if (stack->size_a > 6 && stack->size_a < 90)
		min_max_algo(stack);
	else if (stack->size_a >= 90 && stack->size_a < 250)
		huge_sort(stack);
	else if (stack->size_a >= 250)
		giga_huge_sort(stack);
}
