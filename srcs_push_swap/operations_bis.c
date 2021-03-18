/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:04:51 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/18 10:49:07 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_ra(t_stack *stack)
{
	int	i;
	int	buff;

	buff = stack->a[0];
	i = 0;
	while (i < stack->size_a - 1)
	{
		stack->a[i] = stack->a[i + 1];
		i++;
	}
	stack->a[stack->size_a - 1] = buff;
}

void	ft_rb(t_stack *stack)
{
	int	i;
	int	buff;

	buff = stack->b[0];
	i = 0;
	while (i < stack->size_b - 1)
	{
		stack->b[i] = stack->b[i + 1];
		i++;
	}
	stack->b[stack->size_b - 1] = buff;
}

void	ft_rr(t_stack *stack)
{
	ft_ra(stack);
	ft_rb(stack);
}

void	ft_rra(t_stack *stack)
{
	int	i;
	int	buff;

	buff = stack->a[stack->size_a - 1];
	i = stack->size_a - 1;
	while (i > 0)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[0] = buff;
}

void	ft_rrb(t_stack *stack)
{
	int	i;
	int	buff;

	buff = stack->b[stack->size_b - 1];
	i = stack->size_b - 1;
	while (i > 0)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[0] = buff;
}
