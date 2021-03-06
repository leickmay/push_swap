/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:15:25 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/24 16:31:12 by leickmay         ###   ########lyon.fr   */
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
	int		*big_tab;
	int		*small_tab;
	int		min;
	int		median;
	int		quarter;
	int		quarter3;
	int		decile1;
	int		decile2;
	int		decile3;
	int		decile4;
	int		decile5;
	int		decile6;
	int		decile7;
	int		decile8;
	int		decile9;
	int		decile10;
}				t_stack;

typedef struct s_pos
{
	int	min_pos;
	int	min_value;
	int	min_dist_bottom;
	int	min_closest;
	int	max_pos;
	int	max_value;
	int	max_dist_bottom;
	int	max_closest;
	int	median_value;
	int	median_pos;
}				t_pos;

typedef struct s_pos_b
{
	int	min_pos;
	int	min_value;
	int	min_dist_bottom;
	int	min_closest;
	int	max_pos;
	int	max_value;
	int	max_dist_bottom;
	int	max_closest;
	int	closest_value;
	int	closest_pos;
}				t_pos_b;

/*****DEBUG*****/
void	afficher_piles(t_stack *stack);
/*****DEBUG*****/

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
int		check_sorted(t_stack *stack);
int		check_sorted_a(t_stack *stack);
int		check_sorted_b(t_stack *stack);
int		check_sorted_b_reversed(t_stack *stack);
void	sort_instructions(t_stack *stack);
void	three_sort_algo(t_stack *stack);
void	three_sort_algo_b(t_stack *stack);
void	push_smallest_b(t_stack *stack, int smallest);
void	six_sort_algo(t_stack *stack);
void	build_big_tab_find_biggest(int	*tab, int size, t_stack *stack);
int		*ft_copy_int_tab(t_stack *stack);
void	build_big_tab(t_stack *stack);
int		find_biggest_2(t_stack *stack, int i);
int		find_smallest_b(t_stack *stack);
int		find_biggest_b(t_stack *stack);
void	ten_sort_algo(t_stack *stack);
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
void	sort_instructions(t_stack *stack);
void	two_reverse_sort_b(t_stack *stack);
void	min_max_algo(t_stack *stack);
void	init_t_pos_a(t_stack *stack, t_pos *pos);
void	init_t_pos_b(t_stack *stack, t_pos_b *pos);
void	find_closest_value(t_stack *stack, t_pos_b *pos);
void	push_values_end(t_stack *stack, t_pos *pos);
void	huge_sort(t_stack *stack);
void	push_max_b_on_a(t_stack *stack);
void	set_last_push(t_stack *stack, int last_push);
void	giga_huge_sort(t_stack *stack);

#endif