/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:17:57 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/18 16:48:01 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>

int	rotate_bigger_end(t_stack *stack)
{
	int	i;
	int	r;

	i = 1;
	r = 0;
	while (i < stack->size_a)
	{
		if (stack->a[0] > stack->a[i])
			r = 1;
		else
		{
			r = 0;
			break ;
		}
		i++;
	}
	if (r == 1)
	{
		ft_putstr("ra\n");
		which_action("ra", stack);
	}
	int j = 0;
	printf("--PILE A--\n");
	while (j < stack->size_a)
	{
		printf("j : %d -> %d\n", j, stack->a[j]);
		j++;
	}
	return (r);
}


void	three_sort_algo(t_stack *stack)
{
	//1
	//2
	//3
//
	//2   1  sa
	//1   2
	//3   3 
//
	//3   2   1   sa  rra
	//2   3   2
	//1   1   3
//
	//3  1  ra
	//1  2
	//2  3
//
	//2  1  rra
	//3  2
	//1  3
//
	//1  3  2  1  ra sa rra
	//3  2  3  2
	//2  1  1  3
	if (stack->size_a == 2)
	{
		if (stack->a[0] > stack->a[1])
			which_action("sa", stack);
	}
	if (stack->size_a == 3)
	{
		while (check_sorted_a(stack) == 0)
		{
			if (stack->a[0] > stack->a[1] && stack->a[0] > stack->a[2])
				which_action("ra", stack);
			if (stack->a[0] > stack->a[1] && stack->a[1] < stack->a[2])
				which_action("sa", stack);
			if (stack->a[0] > stack->a[1] && stack->a[1] > stack->a[2] && \
			stack->a[0] > stack->a[2])
				which_action("sa", stack);
			if (stack->a[0] < stack->a[1] && stack->a[2] < stack->a[1] && \
			stack->a[2] < stack->a[0])
				which_action("rra", stack);
			if (stack->a[0] < stack->a[1] && stack->a[2] < stack->a[1] && \
			stack->a[2] > stack->a[0])
				which_action("ra", stack);
			check_sorted_a(stack);
		}
	}
}

void	three_sort_algo_b(t_stack *stack)
{
	if (stack->size_b == 2)
	{
		if (stack->b[0] > stack->b[1])
			which_action("sb", stack);
	}
	if (stack->size_b == 3)
	{
		while (check_sorted_b(stack) == 0)
		{
			if (stack->b[0] > stack->b[1] && stack->b[0] > stack->b[2])
				which_action("rb", stack);
			if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2])
				which_action("sb", stack);
			if (stack->b[0] > stack->b[1] && stack->b[1] > stack->b[2] && \
			stack->b[0] > stack->b[2])
				which_action("sb", stack);
			if (stack->b[0] < stack->b[1] && stack->b[2] < stack->b[1] && \
			stack->b[2] < stack->b[0])
				which_action("rrb", stack);
			if (stack->b[0] < stack->b[1] && stack->b[2] < stack->b[1] && \
			stack->b[2] > stack->b[0])
				which_action("rb", stack);
			check_sorted_b(stack);
		}
	}
}

void	two_reverse_sort_b(t_stack *stack)
{
	if (stack->size_b == 2)
	{
		if (stack->b[0] < stack->b[1])
			which_action("sb", stack);
	}
}

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

void	push_smallest_b(t_stack *stack, int smallest)
{
	int	middle;
	int	i;
	
	middle = stack->size_a / 2;
	if (smallest > middle)
	{
		i = 0;
		while (i < stack->size_a - smallest)
		{
			which_action("rra", stack);
			i++;
		}
	}
	else
	{
		i = smallest;
		while (i > 0)
		{
			which_action("ra", stack);
			i--;
		}
	}
	which_action("pb", stack);
}

void	five_sort_algo(t_stack *stack)
{
	//1
	//2
	//3
	//4
	//5
//
	//2
	//1
	//3
	//4
	//5
//
	//5   2
	//2   4
	//4   3
	//3   1
	//1
	
	int	smallest;
	
	smallest = find_smallest(stack);
	push_smallest_b(stack, smallest);
	smallest = find_smallest(stack);
	push_smallest_b(stack, smallest);
	three_sort_algo(stack);
	two_reverse_sort_b(stack);
	which_action("pa", stack);
	which_action("pa", stack);
}

void	ten_sort_algo(t_stack *stack)
{
	
}

void	sort_instructions(t_stack *stack)
{
	int i;
	int	p;

	i = 0;
	p = 0;
	if (stack->size_a <= 3)
		three_sort_algo(stack);
	else if (stack->size_a <= 5 && stack->size_a > 3)
		five_sort_algo(stack);
	else if (stack->size_a > 5 && stack->size_a <= 10)
		ten_sort_algo(stack);
	//while (p < stack->size_a - 1)
	//{
	//	printf("sort : %d  -  %d\n", stack->a[i], stack->a[stack->size_a - 1 - p]);
	//	if (stack->a[0] > stack->a[stack->size_a - 1 - p])
	//	{
	//		ft_putstr("pb\n");
	//		which_action("pb", stack);
	//	}
	//	else
	//	{
	//		ft_putstr("ra\n");
	//		which_action("ra", stack);
	//		p++;
	//	}
	//}
	//		if (rotate_bigger_end(stack) == 1)
	//	{
	//		ft_putstr("pa\n");
	//		which_action("pa", stack);
	//		while (rotate_bigger_end(stack))
	//			rotate_bigger_end(stack);
	//	}
	//	ft_putstr("sa\n");
	//	which_action("sa", stack);
}