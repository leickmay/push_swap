/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 10:26:46 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 10:41:23 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

void	push_max_b_on_a(t_stack *stack)
{
	int	big;

	while (stack->size_b > 0)
	{
		big = find_biggest_b(stack);
		//printf("big %d -> %d\n", big, stack->b[big]);
		if (big > stack->size_b / 2)
		{
			while (big < stack->size_b)
			{
				which_action("rrb", stack);
				big++;
			}
		}
		else
		{
			while (big > 0)
			{
				which_action("rb", stack);
				big--;
			}
		}
		which_action("pa", stack);
	}
}

void	hundred_sort(t_stack *stack)
{
	//printf("median : %d\n", stack->median);
	int	half;
	int	quarter;
	int	quarter3;
	//int	last_push;

	//afficher_piles(stack);
	half = stack->size_a / 2;
	quarter = stack->size_a / 4;
	quarter3 = stack->size_a - quarter;
	//printf("half : %d\n", half);
	//printf("quarter : %d quarter3 : %d size : %d stackquarter3 : %d stackquarter : %d median : %d\n", 
	//quarter, quarter3, stack->size_a, stack->quarter3, stack->quarter, stack->median);
	//printf("median : %d, size : %d, half : %d\n", stack->median, stack->size_a, half);
	while (stack->size_a > half)
	//int i = 0;
	//while (i < 10)
	{
		if (stack->a[0] >= stack->median)
			which_action("pb", stack);
		else
			which_action("ra", stack);
			//i++;
	}
	//printf("stack size %d  %d\n", stack->size_a, stack->size_a - (stack->size_a / 2));
	//afficher_piles(stack);
	push_max_b_on_a(stack);
	//printf("size %% 4 : %d\n", stack->size_a % 4);
	//if (stack->size_a % 4 == 3)
	//	quarter3--;
	//last_push = stack->a[0];
	//afficher_piles(stack);
	if (stack->size_a % 2 == 1)
		half++;
	//printf("half : %d median : %d\n", half, stack->median);
	while (stack->size_a > half)
	//int i = 0;
	//while (i < 10)
	{
		//printf("size a : %d\n", stack->size_a);
		if (stack->a[0] < stack->median)
			which_action("pb", stack);
		else
			which_action("rra", stack);
			//i++;
	}
	//afficher_piles(stack);
	//set_last_push(stack, last_push);
	//afficher_piles(stack);
	push_max_b_on_a(stack);
	//afficher_piles(stack);
}