/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 22:11:37 by hlin          #+#    #+#                 */
/*   Updated: 2021/05/03 18:02:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ps_swap(int *array, int len)
{
	int	temp;

	if (len > 1)
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
}

static void	ps_push(int *array1, int *array2, int *len1, int *len2)
{
	int	temp;
	int	i;

	if (*len2 > 0)
	{
		temp = array2[0];
		i = 0;
		while (i + 1 < *len2)
		{
			array2[i] = array2[i + 1];
			i++;
		}
		*len2 -= 1;
		i = *len1;
		while (i > 0)
		{
			array1[i] = array1[i - 1];
			i--;
		}
		array1[0] = temp;
		*len1 += 1;
	}
}

static void	ps_rotate(int *array, int len)
{
	int	temp;
	int	i;

	if (len > 1)
	{
		temp = array[0];
		i = 0;
		while (i + 1 < len)
		{
			array[i] = array[i + 1];
			i++;
		}
		array[i] = temp;
	}
}

static void	ps_reverse_rotate(int *array, int len)
{
	int	temp;
	int	i;

	if (len > 1)
	{
		temp = array[len - 1];
		i = len - 1;
		while (i > 0)
		{
			array[i] = array[i - 1];
			i--;
		}
		array[i] = temp;
	}
}

void	run_op(t_stack *stack, char op)
{
	if (op == SA || op == SS)
		ps_swap(stack->stack_a, stack->len_a);
	if (op == SB || op == SS)
		ps_swap(stack->stack_b, stack->len_b);
	else if (op == PA)
		ps_push(stack->stack_a, stack->stack_b, &stack->len_a, &stack->len_b);
	else if (op == PB)
		ps_push(stack->stack_b, stack->stack_a, &stack->len_b, &stack->len_a);
	else if (op == RA || op == RR)
		ps_rotate(stack->stack_a, stack->len_a);
	if (op == RB || op == RR)
		ps_rotate(stack->stack_b, stack->len_b);
	else if (op == RRA || op == RRR)
		ps_reverse_rotate(stack->stack_a, stack->len_a);
	if (op == RRB || op == RRR)
		ps_reverse_rotate(stack->stack_b, stack->len_b);
}
