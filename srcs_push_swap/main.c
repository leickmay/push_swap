/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:32:23 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/20 11:01:48 by leickmay         ###   ########lyon.fr   */
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

char	**first_new_tab(char *line)
{
	char	**new_tab;

	new_tab = malloc(sizeof(char *) * 2);
	if (!new_tab)
		ft_error();
	new_tab[0] = ft_strdup(line);
	new_tab[1] = malloc(sizeof(char));
	if (!new_tab[1])
		ft_error();
	new_tab[1][0] = '\0';
	return (new_tab);
}

void	ft_free_tab(char **op, int i)
{
	while (i >= 0)
	{
		free(op[i]);
		i--;
	}
	free(op);
}

//char	**ft_checker_strjoin(char **op, char *line, int i)
//{
//	char	**new_tab;
//	int		j;
//
//	if (i == 0)
//		new_tab = first_new_tab(line);
//	else
//	{
//		new_tab = malloc(sizeof(char *) * (i + 2));
//		j = 0;
//		while (j < i)
//		{
//			new_tab[j] = ft_strdup(op[j]);
//			j++;
//		}
//		new_tab[j] = ft_strdup(line);
//		new_tab[j + 1] = malloc(sizeof(char));
//		if (!new_tab[j + 1])
//			ft_error();
//		new_tab[j + 1][0] = '\0';
//		ft_free_tab(op, i);
//	}
//	return (new_tab);
//}
//
//void	get_operations(t_stack *stack)
//{
//	char	*line;
//	char	**op;
//
//	while (get_next_line(1, &line))
//	{
//		check_line_chars(line);
//		op = ft_checker_strjoin(op, line, stack->size_list);
//		free(line);
//		stack->size_list++;
//	}
//	free(line);
//	stack->op = op;
//}

int	main(int argc, char **argv)
{
	t_stack	stack;

	//printf("%s\n", argv[1]);
	//printf("argc : %d\n", argc);
	if (argc == 1)
		exit(0);
	//else if (argc == 2)
		//init_stack_args(&stack, argv[1]);
	//else
	//printf("argc : %d\n", argc);
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
	sort_instructions(&stack);
	//get_operations(&stack);
	//make_operations(&stack);
	//display_stack(&stack);
	stack.sorted = check_sorted(&stack);
	//printf("is sorted : %d\n", stack.sorted);
	free(stack.a);
	free(stack.b);
	return (0);
}
