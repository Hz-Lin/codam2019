/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/28 23:36:02 by hlin          #+#    #+#                 */
/*   Updated: 2021/08/23 23:25:23 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_a(t_stack *stack)
{
	while (!is_sorted(stack->stack_a, stack->len_a, 0, 1))
	{
		if (stack->len_a > 1 && stack->stack_a[1] == get_min(stack->stack_a, stack->len_a))
			proceed_op(stack, SA); //
		if (is_sorted(stack->stack_a, stack->len_a, 0, 1))
			break ;
		stack->med = get_next_med(stack, stack->stack_a, stack->len_a);
		stack->dist = get_dist_to_med(stack->stack_a, stack->len_a, stack->med);
		
	}
}

void	quick_sort(t_stack *stack)
{
	int	i;

	i = 0;
	stack->tab_med = (int *)ft_memalloc(sizeof(int) * stack->param);
	while (i < stack->param)
	{
		stack->tab_med[i] = INT_MIN;
		i++;
	}
	stack->tab_med_i = 0;
	stack->first_round = 0;
	while (!is_sorted(stack->stack_a, stack->len_a, 0, 1) ||
			!is_sorted(stack->stack_b, stack->len_b, 0, 0))
	{
		check_a(stack); //
		stack->first_round = 1;
		check_b(stack); //
	}
	while (stack->len_b)
		proceed_op(stack, PA);
}
