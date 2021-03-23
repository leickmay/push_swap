/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:32:23 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/23 17:33:12 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
/**********DEBUG********************/
#include <stdio.h>
/**********DEBUG********************/
/**********DEBUG********************/
void	display_stack(t_stack *stack)
{
	int i = 0;
	printf("pile a :\n");
	while (i < stack->size_a)
	{
		printf("i : %d -> %d\n", i, stack->a[i]);
		i++;
	}
	printf("pile b :\n");
	i = 0;
	while (i < stack->size_b)
	{
		printf("i : %d -> %d\n", i, stack->b[i]);
		i++;
	}
}
/**********DEBUG********************/

void	init_median(t_stack *stack)
{
	int	*tab;

	tab = ft_array_dup(stack->a, stack->size_a);
	ft_sort_int_tab(tab, stack->size_a);
	int i = 0;
	while (i < stack->size_a)
	{
		printf("%d, ", tab[i]);
		i++;
	}
	stack->median = tab[stack->size_a / 2];
	printf("median %d\n", stack->median);
	stack->quarter = tab[stack->size_a / 4];
	stack->quarter3 = tab[stack->size_a - stack->size_a / 4];
	printf("quarter : %d\nquarter3 : %d\n", stack->quarter, stack->quarter3);
	free(tab);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	//printf("%s\n", argv[1]);
	//printf("argc : %d\n", argc);
	if (argc == 1)
		exit(0);
	init_stack(&stack, argc, argv);
	//	int i = 0;
	//while (i < argc)
	//{
	//	printf("argv[%d] = %s\n", i, argv[i]);
	//	i++;
	//}
	//display_stack(&stack);
	//int i = 0;
	//while (i < stack.size_a)
	//{
	//	printf("%d\n", stack.a[i]);
	//	i++;
	//}
	init_median(&stack);
	sort_instructions(&stack);
	//get_operations(&stack);
	//make_operations(&stack);
	//display_stack(&stack);
	stack.sorted = check_sorted(&stack);
	//printf("is sorted : %d\n", stack.sorted);
	//afficher_piles(&stack);
	//free(stack.a);
	//free(stack.b);
	//free(stack.big_tab);
	
	return (0);
}
