/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:32:23 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 15:39:32 by leickmay         ###   ########lyon.fr   */
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
	//int i = 0;
	//while (i < stack->size_a)
	//{
	//	printf("%d, ", tab[i]);
	//	i++;
	//}
	//i = 0;
	//printf("\n");
	//while (i < stack->size_a)
	//{
	//	printf("%d, ", stack->a[i]);
	//	i++;
	//}
	//printf("\n");
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
	//printf("---DECILES---\n");
	//printf("1 : %d\n", stack->decile1);
	//printf("2 : %d\n", stack->decile2);
	//printf("3 : %d\n", stack->decile3);
	//printf("4 : %d\n", stack->decile4);
	//printf("5 : %d\n", stack->decile5);
	//printf("6 : %d\n", stack->decile6);
	//printf("7 : %d\n", stack->decile7);
	//printf("8 : %d\n", stack->decile8);
	//printf("9 : %d\n", stack->decile9);
	//printf("10 : %d\n", stack->decile10);
	
	

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
	init_decile(&stack);
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
