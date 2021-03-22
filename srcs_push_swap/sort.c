/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:17:57 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/22 14:37:19 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

/*****DEBUG*****/
void	afficher_piles(t_stack *stack)
{
	int a = 0;
	printf("PILE A-----\n");
	while (a < stack->size_a)
	{
		printf("a : %d -> %d\n", a, stack->a[a]);
		a++;
	}
	int b = 0;
	printf("PILE B-----\n");
	while (b < stack->size_b)
	{
		printf("b : %d -> %d\n", b, stack->b[b]);
		b++;
	}
}
/*****DEBUG*****/



int		find_smallest(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stack->size_a)
	{
		if (stack->a[i] > stack->a[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

int		find_biggest(t_stack *stack)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (i < stack->size_a)
	{
		if (stack->a[i] > stack->a[big])
			big = i;
		i++;
	}
	return (big);
}

int		find_smallest_b(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < stack->size_b)
	{
		if (stack->b[i] > stack->b[j])
		{
			i++;
			j = 0;
		}
		j++;
	}
	return (i);
}

int		find_biggest_b(t_stack *stack)
{
	int	i;
	int	big;

	i = 0;
	big = 0;
	while (i < stack->size_b)
	{
		if (stack->b[i] > stack->b[big])
			big = i;
		i++;
	}
	return (big);
}

void	big_range_algo(t_stack *stack)
{
	int	quarter;
	int	middle;
	int big;
	int i;
afficher_piles(stack);
	if (stack->size_a % 2 == 0)
		i = stack->size_a / 4 - 1;
	else
		i = stack->size_a / 4;
	middle = stack->size_a / 2;
	quarter = stack->size_a / 4;
	build_big_tab(stack);
	while (stack->size_b < quarter)
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
}

void	sort_instructions(t_stack *stack)
{
	//if (stack->size_a <= 3)
	//	three_sort_algo(stack);
	//else if (stack->size_a <= 6 && stack->size_a > 3)
	//	six_sort_algo(stack);
	//else if (stack->size_a > 6 && stack->size_a <= 100)
	//	ten_sort_algo(stack);
	//else
	//	big_range_algo(stack);
	min_max_algo(stack);


}


//sort 10 ~ 46
//sort 100 ~ 1600