/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   data_min_max.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 15:30:39 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/21 14:53:56 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	get_min(int *array, int len)
{
	int	i;
	int	min;

	i = 0;
	min = INT_MAX;
	while (i < len)
	{
		if (array[i] < min)
			min = array[i];
		i++;
	}
	return (min);
}

int	get_max(int *array, int len)
{
	int	i;
	int	max;

	i = 0;
	max = INT_MIN;
	while (i < len)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

int	find_max_pos(int *array, int len)
{
	int	i;
	int	tmp;
	int	index;

	if (len == 0)
		return (-1);
	i = 0;
	index = 0;
	tmp = array[i];
	while (i < len)
	{
		if (tmp < array[i])
		{
			tmp = array[i];
			index = i;
		}
		i++;
	}
	return (index);
}
