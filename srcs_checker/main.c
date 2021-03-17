/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 13:32:23 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/17 15:54:52 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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

char	**ft_checker_strjoin(char **op, char *line, int i)
{
	char	**new_tab;
	int		j;

	if (i == 0)
		new_tab = first_new_tab(line);
	else
	{
		new_tab = malloc(sizeof(char *) * (i + 2));
		j = 0;
		while (j < i)
		{
			new_tab[j] = ft_strdup(op[j]);
			j++;
		}
		new_tab[j] = ft_strdup(line);
		new_tab[j + 1] = malloc(sizeof(char));
		if (!new_tab[j + 1])
			ft_error();
		new_tab[j + 1][0] = '\0';
		ft_free_tab(op, i);
	}
	return (new_tab);
}

void	get_operations(t_stack *stack)
{
	char	*line;
	char	**op;

	while (get_next_line(1, &line))
	{
		check_line_chars(line);
		op = ft_checker_strjoin(op, line, stack->size_list);
		free(line);
		stack->size_list++;
	}
	free(line);
	stack->op = op;
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	if (argc == 1)
		exit(0);
	init_stack(&stack, argc, argv);
	get_operations(&stack);
	make_operations(&stack);
	check_sorted(&stack);
	free(stack.a);
	free(stack.b);
	return (0);
}
