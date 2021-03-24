/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:32:23 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 17:10:43 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_median(t_stack *stack)
{
	int	*tab;

	tab = ft_array_dup(stack->a, stack->size_a);
	ft_sort_int_tab(tab, stack->size_a);
	stack->median = tab[stack->size_a / 2];
	stack->quarter = tab[stack->size_a / 4];
	stack->quarter3 = tab[stack->size_a - stack->size_a / 4];
	free(tab);
}

void	init_decile(t_stack *stack)
{
	int	*tab;

	tab = ft_array_dup(stack->a, stack->size_a);
	ft_sort_int_tab(tab, stack->size_a);
	stack->decile1 = tab[stack->size_a / 10 - 1];
	stack->decile2 = tab[stack->size_a / 10 * 2 - 1];
	stack->decile3 = tab[stack->size_a / 10 * 3 - 1];
	stack->decile4 = tab[stack->size_a / 10 * 4 - 1];
	stack->decile5 = tab[stack->size_a / 10 * 5 - 1];
	stack->decile6 = tab[stack->size_a / 10 * 6 - 1];
	stack->decile7 = tab[stack->size_a / 10 * 7 - 1];
	stack->decile8 = tab[stack->size_a / 10 * 8 - 1];
	stack->decile9 = tab[stack->size_a / 10 * 9 - 1];
	stack->decile10 = tab[stack->size_a / 10 * 10 - 1];
	free(tab);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		exit(0);
	init_stack(&stack, argc, argv);
	if (check_sorted(&stack))
		return (0);
	init_median(&stack);
	init_decile(&stack);
	sort_instructions(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
