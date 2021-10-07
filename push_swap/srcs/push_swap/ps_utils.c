/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_utils.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/07/28 22:28:58 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/29 17:03:11 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
		ft_putendl_fd("Error (read)", 2);
	else if (status == 4)
		ft_putendl_fd("Error (malloc)", 2);
	return (-1);
}

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

int	is_sorted(int *array, int len, int start, int inc)
{
	int		i;

	i = start;
	if (inc)
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
