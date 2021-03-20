/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:40:44 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/20 15:29:10 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	build_big_tab_find_biggest(int	*tab, int size, t_stack *stack)
{
	int	i;
	int j;
	int	big;

	j = 0;
	while (j < size)
	{			
		i = 0;
		big = 0;
		while (i < stack->size_a)
		{
			if (tab[i] > tab[big])
				big = i;
			i++;
		}
		stack->big_tab[j] = tab[big];
		tab[big] = -2147483648;
		j++;
	}
	free(tab);
}

int	*ft_copy_int_tab(t_stack *stack)
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * stack->size_a);
	if (!tab)
		ft_error();
	i = 0;
	while (i < stack->size_a)
	{
		tab[i] = stack->a[i];
		i++;
	}
	return (tab);
}

void	build_big_tab(t_stack *stack)
{
	int	to_sort;
	int *tab;

	tab = ft_copy_int_tab(stack);
	if (stack->size_a % 2 == 0)
		to_sort = stack->size_a / 2;
	else
		to_sort = stack->size_a / 2 + 1;
	stack->big_tab = malloc(sizeof(int) * to_sort);
	if (!stack->big_tab)
		ft_error();
	//printf("to_sort : %d\n", to_sort);
	build_big_tab_find_biggest(tab, to_sort, stack);
	//i = 3;
	//while (i >= 0)
	//{
	//	printf("big_tab[%d] = %d\n", i, stack->big_tab[i]);
	//	i--;
	//}
	
}

int		find_biggest_2(t_stack *stack, int i)
{
	int	j;
	int	big;

	j = 0;
	big = 0;
	while (j < stack->size_a)
	{
		if (stack->a[j] == stack->big_tab[i])
			big = j;
		j++;
	}
	return (big);
}

void	ten_sort_algo(t_stack *stack)
{
	int	middle;
	int	big;
	int	small;
	int	to_sort;
	int i;
	if (stack->size_a % 2 == 0)
		to_sort = stack->size_a / 2;
	else
		to_sort = stack->size_a / 2 + 1;
	i = to_sort - 1;
	//printf("to_sort : %d\n", to_sort);
	build_big_tab(stack);
	while (stack->size_b < stack->size_a)
	{
		big = find_biggest_2(stack, i);
		//printf("biggest : %d - > %d\n", big, stack->a[big]);
		//big = stack->big_tab[i];
		//printf("biggest : %d - > %d\n", big, stack->a[big]);
		middle = stack->size_a / 2;
		if (big >= middle)
		{
			while (big < stack->size_a)
			{
				which_action("rra", stack);
				big++;
			}
			which_action("pb", stack);
		}
		else
		{
			while (big > 0)
			{
				which_action("ra", stack);
				big--;
			}
			which_action("pb", stack);
		}
		i--;
	}
	//afficher_piles(stack);
	while (stack->size_b > 0)
		which_action("pa", stack);
	//afficher_piles(stack);
	
	big = find_biggest(stack);
	small = find_smallest(stack);
	to_sort = stack->size_a - big - 1;
	//printf("size a : %d\n", stack->size_a);
	//printf("small : %d -> %d\n", small, stack->a[small]);
	//printf("biggest : %d - > %d\n", big, stack->a[big]);
	//printf("to_sort : %d \n", to_sort);
	//afficher_piles(stack);
	while (to_sort > 0)
	{
		small = find_smallest(stack);
		//printf("smallest : %d - > %d\n", small, stack->a[small]);
		middle = stack->size_a / 2;
		if (small >= middle)
		{
			while (small < stack->size_a)
			{
				which_action("rra", stack);
				small++;
			}
			which_action("pb", stack);
		}
		else
		{
			while (small > 0)
			{
				which_action("ra", stack);
				small--;
			}
			which_action("pb", stack);
		}
		to_sort--;
	}
	while (stack->size_b > 0)
		which_action("pa", stack);
	//afficher_piles(stack);
}
