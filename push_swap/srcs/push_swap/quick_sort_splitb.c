/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort_splitb.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/28 16:52:17 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/28 17:29:53 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_med_b(t_stack *s, int *array)
{
	if (s->is_med && find_target(array, s->dist, s->med, 3) != INT_MIN
		&& s->len_a > 1)
	{
		s->med_pushed = 1;
		proceed_op(s, RA);
	}
	else if (s->is_med && find_target(array, s->dist, s->med, 2) == INT_MIN)
		s->med_pushed = 1;
	else if (s->med_pushed
		&& find_target (array, s->dist, s->med, 3) == INT_MIN)
		proceed_op(s, RRA);
}

static void	res_rotated_b(int count, t_stack *s, int *array)
{
	while (count && !is_sorted(array, s->len_b, 0, 0))
	{
		proceed_op(s, RRB);
		count--;
	}
}

void	split_b(t_stack *s, int *array)
{
	int	op;
	int	count;

	count = 0;
	s->med_pushed = 0;
	while (!s->med_pushed || find_target(array, s->dist, s->med, 3) != INT_MIN)
	{
		s->is_med = 0;
		if (array[0] >= s->med)
		{
			if (array[0] == s->med)
				s->is_med = 1;
			s->dist--;
			op = PA;
		}
		else
		{
			count++;
			op = RB;
		}
		proceed_op(s, op);
		check_med_b(s, s->stack_b);
	}
	res_rotated_b(count, s, array);
}
