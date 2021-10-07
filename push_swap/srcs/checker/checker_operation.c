/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker_operation.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/17 18:28:43 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/29 17:08:12 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	ps_swap(t_stack *stack, int *array, int len)
{
	int	temp;

	if (len > 1)
	{
		temp = array[0];
		array[0] = array[1];
		array[1] = temp;
	}
	stack->op_ok = 1;
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

static void	ps_rotate(t_stack *stack, int *array, int len)
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
	stack->op_ok = 1;
}

static void	ps_reverse_rotate(t_stack *stack, int *array, int len)
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
	stack->op_ok = 1;
}

int	checker_operations(char *line, t_stack *stack)
{
	if (ft_strequ(line, "sa") || ft_strequ(line, "ss"))
		ps_swap(stack, stack->stack_a, stack->len_a);
	if (ft_strequ(line, "sb") || ft_strequ(line, "ss"))
		ps_swap(stack, stack->stack_b, stack->len_b);
	else if (ft_strequ(line, "pa"))
	{
		stack->op_ok = 1;
		ps_push(stack->stack_a, stack->stack_b, &stack->len_a, &stack->len_b);
	}
	else if (ft_strequ(line, "pb"))
	{
		stack->op_ok = 1;
		ps_push(stack->stack_b, stack->stack_a, &stack->len_b, &stack->len_a);
	}
	else if (ft_strequ(line, "ra") || ft_strequ(line, "rr"))
		ps_rotate(stack, stack->stack_a, stack->len_a);
	if (ft_strequ(line, "rb") || ft_strequ(line, "rr"))
		ps_rotate(stack, stack->stack_b, stack->len_b);
	else if (ft_strequ(line, "rra") || ft_strequ(line, "rrr"))
		ps_reverse_rotate(stack, stack->stack_a, stack->len_a);
	if (ft_strequ(line, "rrb") || ft_strequ(line, "rrr"))
		ps_reverse_rotate(stack, stack->stack_b, stack->len_b);
	if (!stack->op_ok)
		return (0);
	return (1);
}
