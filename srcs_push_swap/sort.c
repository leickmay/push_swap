/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 11:17:57 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/20 12:29:09 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

#include <stdio.h>


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
	//1    2     sb rrb
	//2    1
	//3    3
//
	//2   3  rrb
	//1   2
	//3   1
//
	//3     
	//2      
	//1      
//
	//3  2  3  rrb sb
	//1  3  2
	//2  1  1
//
	//2  3  sb
	//3  2
	//1  1
//
	//1  3 rb
	//3  2
	//2  1
	if (stack->size_b == 2)
	{
		if (stack->b[0] > stack->b[1])
			which_action("sb", stack);
	}
	if (stack->size_b == 3)
	{
		while (check_sorted_b_reversed(stack) == 0)
		{
			if (stack->b[0] < stack->b[1] && stack->b[0] < stack->b[2] && \
			stack->b[1] > stack->b[2])
				which_action("rb", stack);
			if (stack->b[0] > stack->b[1] && stack->b[1] < stack->b[2] && \
			stack->b[0] < stack->b[2])
				which_action("rrb", stack);
			if (stack->b[0] < stack->b[1] && stack->b[1] > stack->b[2] && \
			stack->b[0] > stack->b[2])
				which_action("sb", stack);
			if (stack->b[0] < stack->b[1] && stack->b[0] < stack->b[2] && \
			stack->b[1] < stack->b[2])
				which_action("sb", stack);
			check_sorted_b_reversed(stack);
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

void	six_sort_algo(t_stack *stack)
{
	int	smallest;

	smallest = find_smallest(stack);
	push_smallest_b(stack, smallest);
	smallest = find_smallest(stack);
	push_smallest_b(stack, smallest);
	if (stack->size_a == 4)
	{
		smallest = find_smallest(stack);
		push_smallest_b(stack, smallest);
		three_sort_algo(stack);
		three_sort_algo_b(stack);
		which_action("pa", stack);
		which_action("pa", stack);
		which_action("pa", stack);
	}
	if (stack->size_b == 2)
	{
		three_sort_algo(stack);
		two_reverse_sort_b(stack);
		which_action("pa", stack);
		which_action("pa", stack);
	}
}

//int	sort_pivot(t_stack *stack, int pivot)
//{
//	int	i;
//
//	i = 0;
//	while (i < stack->size_a)
//	{
//		if (i == pivot)
//			i++;
//		if (pivot < 0)
//			pivot = stack->size_a - 1;
//		printf("pivot %d : %d\n", pivot, stack->a[pivot]);
//		if (stack->a[0] <= stack->a[pivot])
//		{
//			which_action("ra", stack);
//			pivot--;
//
//		}
//		else
//		{
//			which_action("pb", stack);
//			pivot--;
//		}
//		i++;
//	}
//	return (pivot);
//}
//
//void	ten_sort_algo(t_stack *stack)
//{
//	int	pivot;
//	int	i;
//
//	i = 0;
//	pivot = stack->size_a - 1;
//	printf("pivot : %d\n", stack->a[pivot]);
//	pivot = sort_pivot(stack, pivot);
//	if (pivot >= stack->size_a / 2)
//	{
//		while (pivot < stack->size_a - 1)
//		{
//			which_action("rra", stack);
//			pivot++;
//		}
//	}
//	else
//	{
//		while (pivot >= 0)
//		{
//			which_action("ra", stack);
//			pivot--;
//		}
//		
//	}
//	i = 0;
//	while (stack->size_b > 0)
//	{
//		which_action("pa", stack);
//		i++;
//	}
//	while (i > 0)
//	{
//		which_action("ra", stack);
//		i--;
//	}
//	int a = 0;
//	printf("PILE A-----\n");
//	while (a < stack->size_a)
//	{
//		printf("a : %d -> %d\n", a, stack->a[a]);
//		a++;
//	}
//	int b = 0;
//	printf("PILE B-----\n");
//	while (b < stack->size_b)
//	{
//		printf("b : %d -> %d\n", b, stack->b[b]);
//		b++;
//	}
//}

//void	ten_sort_algo(t_stack *stack)
//{
//	int	pivot;
//
//	pivot = stack->size_a - 1;
//	//printf("0 : %d, pivot : %d\n", stack->a[0], stack->a[pivot]);
//	while (!check_sorted(stack))
//	{
//		while (pivot > 0)
//		{
//			if (stack->a[0] < stack->a[pivot])
//				which_action("pb", stack);
//			else
//				which_action("ra", stack);
//			pivot--;
//		}
//		if (stack->a[0] > stack->a[1])
//		{
//			which_action("sa", stack);
//			if (pivot == 0)
//				pivot = 1;
//			if (pivot == 1)
//				pivot = 0;
//		}
//		if (stack->b[0] < stack->b[1])
//			which_action("sb", stack);
//		while (stack->size_b > 0)
//		{
//			which_action("pa", stack);
//			pivot++;
//		}
//		pivot--;
//		if (pivot < 0)
//			pivot = stack->size_a - 1;
//		//printf("pivot : %d -> %d\n", pivot, stack->a[pivot]);
//	}
//}



void	ten_sort_algo(t_stack *stack)
{
	int	middle;
	int	big;
	int	small;
	int	to_sort;

	while (stack->size_b < stack->size_a)
	{
		big = find_biggest(stack);
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
	}
	while (stack->size_b > 0)
	{
		which_action("rrb", stack);
		which_action("pa", stack);
	}
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
}

void	sort_instructions(t_stack *stack)
{
	int i;
	int	p;

	i = 0;
	p = 0;
	//int a = 0;
	//printf("PILE A----- avant algo\n");
	//while (a < stack->size_a)
	//{
	//	printf("a : %d -> %d\n", a, stack->a[a]);
	//	a++;
	//}
	if (stack->size_a <= 3)
		three_sort_algo(stack);
	else if (stack->size_a <= 6 && stack->size_a > 3)
		six_sort_algo(stack);
	else if (stack->size_a > 6)
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