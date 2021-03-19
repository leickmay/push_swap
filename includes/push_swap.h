/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:15:25 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/19 12:47:48 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		size_a;
	int		size_b;
	int		size_list;
	int		sorted;
	char	**op;
}				t_stack;

void	ft_error(void);
void	ft_atoi_check(char *str);
void	check_argv(char *argv);
void	check_double(t_stack *stack);
void	check_line_chars(char *line);
void	fill_stack(char **argv, t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_pa(t_stack *stack);
void	ft_pb(t_stack *stack);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);
void	make_operations(t_stack *stack);
void	which_action(char *line, t_stack *stack);
void	fill_stack(char **argv, t_stack *stack);
void	init_stack(t_stack *stack, int argc, char **argv);
void	init_stack_args(t_stack *stack, char *argv);
int	check_sorted(t_stack *stack);
int	check_sorted_a(t_stack *stack);
int	check_sorted_b(t_stack *stack);
int	check_sorted_b_reversed(t_stack *stack);
void	sort_instructions(t_stack *stack);

#endif