/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:06:11 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/17 15:55:05 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_rrr(t_stack *stack)
{
	ft_rra(stack);
	ft_rrb(stack);
}

void	make_operations(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_list)
	{
		which_action(stack->op[i], stack);
		i++;
	}
}

void	which_action(char *line, t_stack *stack)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_sa(stack);
	else if (ft_strcmp(line, "sb") == 0)
		ft_sb(stack);
	else if (ft_strcmp(line, "ss") == 0)
		ft_ss(stack);
	else if (ft_strcmp(line, "pa") == 0)
		ft_pa(stack);
	else if (ft_strcmp(line, "pb") == 0)
		ft_pb(stack);
	else if (ft_strcmp(line, "ra") == 0)
		ft_ra(stack);
	else if (ft_strcmp(line, "rb") == 0)
		ft_rb(stack);
	else if (ft_strcmp(line, "rr") == 0)
		ft_rr(stack);
	else if (ft_strcmp(line, "rra") == 0)
		ft_rra(stack);
	else if (ft_strcmp(line, "rrb") == 0)
		ft_rrb(stack);
	else if (ft_strcmp(line, "rrr") == 0)
		ft_rrr(stack);
	else
		ft_error();
}

void	check_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_a - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
		{
			ft_putstr("KO\n");
			exit(0);
		}
		i++;
	}
	if (stack->size_b > 0)
	{
		ft_putstr("KO\n");
		exit(0);
	}
	ft_putstr("OK\n");
}
