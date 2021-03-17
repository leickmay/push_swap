/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 13:38:09 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/17 15:52:06 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

void	ft_atoi_check(char *str)
{
	long	nb;
	int		neg;

	neg = 1;
	nb = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - '0';
	nb *= neg;
	if (nb < -2147483648 || nb > 2147483647)
		ft_error();
}

void	check_argv(char *argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		if (ft_isdigit(argv[i]) == 0)
		{
			if (i != 0 || argv[0] != '-')
				ft_error();
		}
		i++;
	}
	ft_atoi_check(argv);
}

void	check_double(t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size_a)
	{
		j = 0;
		while (j < i)
		{
			if (stack->a[j] == stack->a[i])
				ft_error();
			j++;
		}
		i++;
	}
}

void	check_line_chars(char *line)
{
	int	error;

	if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0 || \
	ft_strcmp(line, "ss") == 0 || ft_strcmp(line, "pa") == 0 || \
	ft_strcmp(line, "pb") == 0 || ft_strcmp(line, "ra") == 0 || \
	ft_strcmp(line, "rb") == 0 || ft_strcmp(line, "rr") == 0 || \
	ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0 || \
	ft_strcmp(line, "rrr") == 0)
		error = 0;
	else
		error = 1;
	if (error == 1)
		ft_error();
}
