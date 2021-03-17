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

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	get_args(int argc, char **argv, t_stack *stack)
{
	
}

void	fill_stack(char **argv, t_stack *stack)
{
	int		i;

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
	stack->a = malloc(sizeof(int) * (argc - 1));
	if (!stack->a)
		ft_error();
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
}