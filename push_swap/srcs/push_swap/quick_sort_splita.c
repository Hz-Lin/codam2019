/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort_splita.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 17:13:31 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/28 17:28:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	find_target(int *array, int len, int med, char comp)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (comp == 1 && array[i] < med)
			return (i);
		else if (comp == 2 && array[i] == med)
			return (i);
		else if (comp == 3 && array[i] > med)
			return (i);
		i++;
	}
	if (comp == 1)
		return (INT_MAX);
	else
		return (INT_MIN);
}

static void	check_med_a(t_stack *s, int *array)
{
	if (s->is_med && find_target(array, s->dist, s->med, 1) != INT_MAX
		&& s->len_b > 1)
	{
		s->med_pushed = 1;
		proceed_op(s, RB);
	}
	else if (s->is_med && find_target(array, s->dist, s->med, 2) == INT_MIN)
		s->med_pushed = 1;
	else if (s->med_pushed
		&& find_target(array, s->dist, s->med, 1) == INT_MAX)
		proceed_op(s, RRB);
}

static void	res_rotated_a(int count, t_stack *s, int *array)
{
	while (s->first_round && count && !is_sorted(array, s->len_a, 0, 1))
	{
		proceed_op(s, RRA);
		count--;
	}
}

void	split_a(t_stack *s, int *array)
{
	int	op;
	int	count;

	count = 0;
	s->med_pushed = 0;
	while (!s->med_pushed || find_target(array, s->dist, s->med, 1) != INT_MAX)
	{
		s->is_med = 0;
		if (array[0] <= s->med)
		{
			if (array[0] == s->med)
				s->is_med = 1;
			s->dist--;
			op = PB;
		}
		else
		{
			count++;
			op = RA;
		}
		proceed_op(s, op);
		check_med_a(s, s->stack_a);
	}
	res_rotated_a(count, s, array);
}
