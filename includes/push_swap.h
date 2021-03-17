/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 16:15:25 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/17 16:26:43 by leickmay         ###   ########lyon.fr   */
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
	char	**op;
}				t_stack;

#endif