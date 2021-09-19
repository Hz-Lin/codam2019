/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/15 15:18:13 by hlin          #+#    #+#                 */
/*   Updated: 2021/05/05 16:09:03 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	sort_three(t_stack *stack)
{
	int	max_pos;

	max_pos = find_max_pos(stack->stack_a, stack->len_a);
	if (max_pos == 0)
		do_operation(stack, RA, 1);
	if (max_pos == 1)
		do_operation(stack, RRA, 1);
	if (stack->stack_a[0] > stack->stack_a[1])
		do_operation(stack, SA, 1);
}

static int	find_insert_pos(int *array, int len, int elem)
{
	int	i;
	int	pos;

	pos = 0;
	i = 1;
	if (elem < array[0])
		pos = 0;
	else if (elem > array[len - 1])
		pos = len;
	else
	{
		while (i < len)
		{
			if (array[i - 1] < elem && elem < array[i])
				pos = i;
			i++;
		}
	}
	return (pos);
}

static void	shift_a(t_stack *stack, int len, int pos)
{
	int	i;

	i = 0;
	if (pos <= len / 2)
	{
		while (i < pos)
		{
			do_operation(stack, RA, 1);
			i++;
		}
	}
	else
	{
		while (i < len - pos)
		{
			do_operation(stack, RRA, 1);
			i++;
		}
	}
}

static void	insert_to_a(t_stack *stack, int len, int pos)
{
	int	i;
	
	i = 0;
	shift_a(stack, len, pos);
	do_operation(stack, PA, 1);
	if (pos <= len / 2)
	{
		i = pos;
		while (i > 0)
		{
			do_operation(stack, RRA, 1);
			i--;
		}
	}
	else
	{
		i = len - pos + 1;
		while (i >= 0)
		{
			do_operation(stack, RA, 1);
			i--;
		}
	}
}

void	simple_sort(t_stack *stack)
{
	int	pos;
	
	stack->min = get_min(stack->stack_a, stack->len_a);
	stack->max = get_max(stack->stack_a, stack->len_a);
	if (stack->len_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			do_operation(stack, SA);
	}
	else
	{
		while (stack->len_a > 3)
			do_operation(stack, PB);
		sort_three(stack);
		while (stack->len_b > 0)
		{
			pos = find_insert_pos(stack->stack_a, stack->len_a, stack->stack_b[0]);
			insert_to_a(stack, stack->len_a, pos);
		}
	}
}
