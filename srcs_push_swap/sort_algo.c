/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 14:40:44 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/22 17:52:26 by leickmay         ###   ########lyon.fr   */
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
#include <stdio.h>

void	find_slot_max(t_stack *stack)
{
	t_pos_b pos;
	int		middle;

	middle = stack->size_b - (stack->size_b / 2);
	init_t_pos_b(stack, &pos);
	//afficher_piles(stack);
	//printf("-- closest : pos %d value %d\n", pos.closest_pos, stack->b[pos.closest_pos]);
	if (pos.closest_pos >= middle)
	{
		while (pos.closest_pos < stack->size_b - 1)
		{
			which_action("rrb", stack);
			pos.closest_pos++;
			//printf("closest : pos %d value %d\n", pos.closest_pos, stack->b[pos.closest_pos]);
		}
		//printf("--------------------------------slot-----max\n");
		//afficher_piles(stack);
		//printf("-------\n");
		if (stack->a[0] > pos.closest_value)
		{
			which_action("rrb", stack);
			pos.closest_pos = 0;
		}
	}
	else
	{
		while (pos.closest_pos > 0)
		{
			which_action("rb", stack);
			pos.closest_pos--;
			//printf("-->closest : pos %d value %d\n", pos.closest_pos, stack->b[pos.closest_pos]);
		}
		//	printf("--------------------------------slotmax\n");
		//afficher_piles(stack);
		//printf("-------\n");
		if (stack->a[0] < pos.closest_value)
		{
			which_action("rb", stack);
			pos.closest_pos = stack->size_b - 1;
		}
	}
	//printf("Max : pos %d, value %d, dist_bottom %d, closest : %d\n", pos.max_pos, pos.max_value, pos.max_dist_bottom, pos.max_closest);
	//printf("Min : pos %d, value %d, dist_bottom %d, closest : %d\n", pos.min_pos, pos.min_value, pos.min_dist_bottom, pos.min_closest);
	//printf("closest : pos %d value %d\n", pos.closest_pos, stack->b[pos.closest_pos]);
	//printf("a[0] : %d\n", stack->a[0]);
	
}

void	push_min(t_stack *stack, t_pos *pos)
{
	if (pos->min_dist_bottom > pos->min_pos)
	{
		while (pos->min_pos > 0)
		{
			which_action("ra", stack);
			pos->min_pos--;
		}
	}
	else
	{
		while (pos->min_dist_bottom > 0)
		{
			which_action("rra", stack);
			pos->min_dist_bottom--;
		}
	}
	//if (stack->size_b > 1)
	//{
	//	while (stack->a[0] > stack->b[0])
	//		which_action("rb", stack);
	//	which_action("pb", stack);
	//	while (stack->b[stack->size_b - 1] < stack->b[0])
	//		which_action("rrb", stack);
	//}
	//else
	if (stack->size_b > 1)
		find_slot_max(stack);
	which_action("pb", stack);
	//afficher_piles(stack);
}

void	push_max(t_stack *stack, t_pos *pos)
{
	if (pos->max_dist_bottom > pos->max_pos)
	{
		while (pos->max_pos > 0)
		{
			which_action("ra", stack);
			pos->max_pos--;
		}
	}
	else
	{
		while (pos->max_dist_bottom > 0)
		{
			which_action("rra", stack);
			pos->max_dist_bottom--;
		}
	}
	//if (stack->size_b > 1)
	//{
	//	while (stack->a[0] > stack->b[0])
	//		which_action("rb", stack);
	//	which_action("pb", stack);
	//	while (stack->b[stack->size_b - 1] < stack->b[0])
	//		which_action("rrb", stack);
	//}
	//else
	if (stack->size_b > 1)
		find_slot_max(stack);
	which_action("pb", stack);
	//afficher_piles(stack);
}

void	push_values_end(t_stack *stack, t_pos *pos)
{
	//printf("max dist bottom : %d, max pos : %d, max value : %d\n", pos->max_dist_bottom, pos->max_pos, pos->max_value);
	if (pos->max_dist_bottom > pos->max_pos)
	{
		while (pos->max_pos >= 0)
		{
			which_action("ra", stack);
			pos->max_pos--;
		}
	}
	else
	{
		while (pos->max_dist_bottom > 1)
		{
			which_action("rra", stack);
			pos->max_dist_bottom--;
		}
	}
}

void	min_max_algo(t_stack *stack)
{
	//int		middle;
	t_pos	pos;

	//middle = stack->size_a - (stack->size_a / 2);
	//printf("middle : %d\n", middle);
	while (stack->size_a > 0)
	{
		init_t_pos_a(stack, &pos);
		//printf("Max : pos %d, value %d, dist_bottom %d, closest : %d\n", pos.max_pos, pos.max_value, pos.max_dist_bottom, pos.max_closest);
		//printf("Min : pos %d, value %d, dist_bottom %d, closest : %d\n", pos.min_pos, pos.min_value, pos.min_dist_bottom, pos.min_closest);
		//printf("size_a : %d\n", stack->size_a);
		if (pos.max_closest > pos.min_closest)
			push_min(stack, &pos);
		else
			push_max(stack, &pos);
		//afficher_piles(stack);
		//printf("stack-b size -1 : %d\n", stack->b[stack->size_b - 1]);
	}
	while (stack->size_b > 0)
	{
		//which_action("rrb", stack);
		which_action("pa", stack);
	}
	//afficher_piles(stack);
	init_t_pos_a(stack, &pos);
	push_values_end(stack, &pos);
	//while (stack->size_b > 0)
	//{
	//	which_action("rrb", stack);
	//	which_action("pa", stack);
	//}
	//afficher_piles(stack);
}