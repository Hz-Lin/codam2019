/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_median.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 14:54:45 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/27 12:08:15 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	calc_dist(int *array, int len, int i)
{
	int	j;
	int	dist;

	j = 0;
	dist = 0;
	while (j < len)
	{
		if (array[j] > array[i])
			dist++;
		j++;
	}
	return (dist);
}

int	get_med(int *array, int len)
{
	int	i;
	int	dist;
	int	med;
	int	med_pos;

	i = 0;
	med = INT_MIN;
	if (len % 2 == 0)
		med_pos = len / 2 - 1;
	else
		med_pos = (len - 1) / 2;
	while (i < len)
	{
		dist = calc_dist(array, len, i);
		if (dist == med_pos)
		{
			med = array[i];
			break ;
		}
		i++;
	}
	return (med);
}

int	get_next_med(t_stack *stack, int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < stack->param && stack->tab_med[j] != INT_MIN)
		{
			if (array[i] == stack->tab_med[j])
				return (stack->tab_med[j]);
			j++;
		}
		i++;
	}
	return (INT_MIN);
}

int	get_dist_to_med(int *array, int size, int next_med)
{
	int	i;

	i = 0;
	while (i < size && array[i] != next_med)
		i++;
	if (i == size)
		return (0);
	return (i);
}
