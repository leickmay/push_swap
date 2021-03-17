/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:12:18 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/17 16:29:08 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_args(int argc, char **argv, t_stack *stack)
{
	
}

void	init_stack(t_stack *stack, int argc, char **argv)
{
	stack->b = malloc(sizeof(int) * (argc - 1));
	stack->size_a = argc - 1;
	stack->size_b = 0;
	stack->size_list = 0;
	fill_stack(argv, stack);
}


int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		return (0);
	init_stack(&stack, argc, argv);
	get_args(argc, argv, &stack);
}