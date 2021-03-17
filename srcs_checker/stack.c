/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:49:02 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/17 15:55:18 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	fill_stack(char **argv, t_stack *stack)
{
	int		i;

	stack->a = malloc(sizeof(int) * stack->size_a);
	if (stack->a == 0)
		ft_error();
	i = 0;
	while (i < stack->size_a)
	{
		check_argv(argv[i + 1]);
		stack->a[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	check_double(stack);
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	stack->b = malloc(sizeof(int) * (argc - 1));
	if (!stack->b)
		ft_error();
	stack->size_a = argc - 1;
	stack->size_b = 0;
	stack->size_list = 0;
	fill_stack(argv, stack);
}
