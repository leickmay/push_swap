/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leickmay <leickmay@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:14:45 by leickmay          #+#    #+#             */
/*   Updated: 2021/03/23 13:21:20 by leickmay         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_array_dup(int *array, int size)
{
	int	*dup;
	int	i;

	dup = malloc(sizeof(int) * size);
	if (!dup)
		return (0);
	i = 0;
	while (i < size)
	{
		dup[i] = array[i];
		i++;
	}
	return (dup);
}
