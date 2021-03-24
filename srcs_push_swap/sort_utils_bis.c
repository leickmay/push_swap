/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 16:31:57 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 16:32:29 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	if (stack->size_b > 0)
		return (0);
	return (1);
}

int	check_sorted_a(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted_b(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b - 1)
	{
		if (stack->b[i] > stack->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	check_sorted_b_reversed(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_b - 1)
	{
		if (stack->b[i] < stack->b[i + 1])
			return (0);
		i++;
	}
	return (1);
}
