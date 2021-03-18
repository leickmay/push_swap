/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 15:06:11 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/18 16:24:07 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	display_action(char *line)
{
	if (ft_strcmp(line, "sa") == 0)
		ft_putstr("sa\n");
	else if (ft_strcmp(line, "sb") == 0)
		ft_putstr("sb\n");
	else if (ft_strcmp(line, "ss") == 0)
		ft_putstr("ss\n");
	else if (ft_strcmp(line, "pa") == 0)
		ft_putstr("pa\n");
	else if (ft_strcmp(line, "pb") == 0)
		ft_putstr("pb\n");
	else if (ft_strcmp(line, "ra") == 0)
		ft_putstr("ra\n");
	else if (ft_strcmp(line, "rb") == 0)
		ft_putstr("rb\n");
	else if (ft_strcmp(line, "rr") == 0)
		ft_putstr("rr\n");
	else if (ft_strcmp(line, "rra") == 0)
		ft_putstr("rra\n");
	else if (ft_strcmp(line, "rrb") == 0)
		ft_putstr("rrb\n");
	else if (ft_strcmp(line, "rrr") == 0)
		ft_putstr("rrr\n");
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
	display_action(line);
}

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

