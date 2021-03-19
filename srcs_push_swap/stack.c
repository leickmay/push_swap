/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 15:49:02 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/19 14:38:40 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>
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
	stack->sorted = 0;
	fill_stack(argv, stack);
}

int		count_int_str(char	*str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			nb++;
			while (ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (nb);
}

void	ft_split_int(t_stack *stack, char *str)
{
	int		i;
	int		j;
	int		k;
	char	*nb;

	i = 0;
	k = 0;
	stack->a = malloc(sizeof(int) * stack->size_a);
	if (!stack->a)
		ft_error();
	while (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '-')
	{
		if (ft_isdigit(str[i])|| str[i] == '-')
		{
			j = 0;
			while (ft_isdigit(str[i]) || str[i] == '-')
			{
				i++;
				j++;
				printf("%c\n", str[i]);
			}
			i -= j;
			nb = ft_substr(str, i, j);
			printf("nb : %s\n", nb);
			ft_atoi_check(nb);
			i += j;
			stack->a[k] = ft_atoi(nb);
			free(nb);
			k++;
		}
		else
			i++;
	}
	if (str[i] && (!ft_isdigit(str[i]) || str[i] != ' '))
		ft_error();
	int x = 0;
	while (x < stack->size_a)
	{
		printf("%d\n", stack->a[x]);
		x++;
	}
}

void	init_stack_args(t_stack *stack, char *argv)
{
	stack->sorted = 0;
	//printf("%s\n", argv);
	stack->size_b = 0;
	stack->size_a = count_int_str(argv);
	stack->b = malloc(sizeof(int) * stack->size_a);
	if (!stack->b)
		ft_error();
	//printf("size : %d\n", stack->size_a);
	ft_split_int(stack, argv);
}
