/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   quick_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/28 23:36:02 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/28 16:15:17 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	add_med(int **tab_med, int size, int med)
{
	int	i;
	int	*tab;

	tab = *tab_med;
	i = 0;
	while (i < size)
	{
		if (tab[i] == INT_MIN)
		{
			tab[i] = med;
			return ;
		}
		i++;
	}
}

static void	check_a(t_stack *s)
{
	while (!is_sorted(s->stack_a, s->len_a, 0, 1))
	{
		if (s->len_a > 1 && s->stack_a[1] == get_min(s->stack_a, s->len_a))
			proceed_op(s, SA);
		if (is_sorted(s->stack_a, s->len_a, 0, 1))
			break ;
		s->med = get_next_med(s, s->stack_a, s->len_a);
		s->dist = get_dist_to_med(s->stack_a, s->len_a, s->med);
		if (s->med != INT_MIN && s->dist > 2
			&& !is_sorted(s->stack_a, s->dist, 0, 1))
		{
			add_med(&s->tab_med, s->param, get_med(s->stack_a, s->dist));
			s->med = get_next_med(s, s->stack_a, s->dist);
			s->tab_med_i++;
		}
		else if (s->med == INT_MIN)
		{
			add_med(&s->tab_med, s->param, get_med(s->stack_a, s->len_a));
			s->med = s->tab_med[s->tab_med_i];
			s->dist = s->len_a;
			s->tab_med_i++;
		}
		split_a(s, s->stack_a);
	}
}

static void	check_b(t_stack *s)
{
	while (is_sorted(s->stack_a, s->len_a, 0, 1)
		&& !is_sorted(s->stack_b, s->len_b, 0, 0))
	{
		if (s->len_b > 1 && s->stack_b[1] == get_max(s->stack_b, s->len_b))
			proceed_op(s, SB);
		if (is_sorted(s->stack_b, s->len_b, 0, 0))
			break ;
		s->med = get_next_med(s, s->stack_b, s->len_b);
		s->dist = get_dist_to_med(s->stack_b, s->len_b, s->med);
		if (s->med != INT_MIN && s->dist > 2
			&& !is_sorted(s->stack_b, s->dist, 0, 1))
		{
			add_med(&s->tab_med, s->param, get_med(s->stack_b, s->dist));
			s->med = get_next_med(s, s->stack_b, s->dist);
			s->tab_med_i++;
		}
		else if (s->med == INT_MIN)
		{
			add_med(&s->tab_med, s->param, get_med(s->stack_b, s->len_b));
			s->med = s->tab_med[s->tab_med_i];
			s->dist = s->len_b;
			s->tab_med_i++;
		}
		split_b(s, s->stack_b);
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
	while (!is_sorted(stack->stack_a, stack->len_a, 0, 1)
		|| !is_sorted(stack->stack_b, stack->len_b, 0, 0))
	{
		check_a(stack);
		stack->first_round = 1;
		check_b(stack);
	}
	while (stack->len_b)
		proceed_op(stack, PA);
}
