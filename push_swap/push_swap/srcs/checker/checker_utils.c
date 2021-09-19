/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_utils.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/05 22:59:50 by hlin          #+#    #+#                 */
/*   Updated: 2021/04/20 18:05:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	check_args(char **arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i])
	{
		j = 0;
		if (arg[i][j] == '-' || arg[i][j] == '+')
		{
			j++;
			if (!arg[i][j])
				return (0);
		}
		while (arg[i][j])
		{
			if (!ft_isdigit(arg[i][j]))
				return (0);
			j++;
		}
		if (ft_strlen(arg[i]) > 11 || ft_atoss(arg[i]) > INT_MAX
			|| ft_atoss(arg[i]) < INT_MIN)
			return (0);
		i++;
	}
	return (i);
}

int	find_dup(t_stack stack)
{
	int	i;
	int	j;

	i = 0;
	while (i + 1 < stack.param)
	{
		j = 0;
		while (j < stack.param)
		{
			if (i == j)
				j++;
			if (stack.stack_a[i] == stack.stack_a[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_end(int status)
{
	if (status == 0 || status == 10)
	{
		if (status == 0)
			ft_putendl_fd("OK", 1);
		return (0);
	}
	if (status == 1)
		ft_putendl_fd("Error", 2);
	else if (status == 2)
	{
		ft_putendl_fd("KO", 1);
		return (0);
	}
	else if (status == 3)
		ft_putendl_fd("Error while reading", 2);
	else if (status == 4)
		ft_putendl_fd("Error during malloc", 2);
	return (-1);
}

int	is_sorted(int *array, int len, int start, int increase)
{
	int	i;

	i = start;
	if (increase)
	{
		while (i + 1 < len)
		{
			if (array[i] >= array[i + 1])
				return (0);
			i++;
		}
	}
	else
	{
		while (i + 1 < len)
		{
			if (array[i] <= array[i + 1])
				return (0);
			i++;
		}
	}
	return (1);
}

int	is_ranked(t_stack *stack, int *array, int len)
{
	int	i;
	int	count;
	int	rank;

	i = 0;
	count = 0;
	rank = -1;
	while (i + 1 < len)
	{
		if (count == 0 && array[i] > array[i + 1])
		{
			rank = i;
			count++;
			i++;
		}
		if (i + 1 < len && count > 0 && (array[i] > array[i + 1] || (array[i] < array[i - 1] && (array[i] != stack->min || array[i - 1] != stack->max))))
			return (-1);
		i++;
	}
	return (rank);
}
