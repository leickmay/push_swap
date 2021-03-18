/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:02:54 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/18 15:26:54 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sa(t_stack *stack)
{
	int	buff;

	if (stack->size_a >= 2)
	{
		buff = stack->a[0];
		stack->a[0] = stack->a[1];
		stack->a[1] = buff;
	}
}

void	ft_sb(t_stack *stack)
{
	int	buff;

	if (stack->size_b >= 2)
	{
		buff = stack->b[0];
		stack->b[0] = stack->b[1];
		stack->b[1] = buff;
	}
}

void	ft_ss(t_stack *stack)
{
	ft_sa(stack);
	ft_sb(stack);
}

void	ft_pa(t_stack *stack)
{
	int	i;

	if (stack->size_b > 0)
	{
		stack->size_a++;
		i = stack->size_a - 1;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->size_b--;
	}
}

void	ft_pb(t_stack *stack)
{
	int	i;

	if (stack->size_a > 0)
	{
		stack->size_b++;
		i = stack->size_b - 1;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->size_a--;
	}
}
