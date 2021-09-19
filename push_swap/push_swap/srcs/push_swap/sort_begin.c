/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_begin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 23:35:11 by hlin          #+#    #+#                 */
/*   Updated: 2021/08/23 23:23:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	print_op(t_stack *stack, char op)
{
	display_color(stack, 1);
	if (op == SA)
		ft_putendl("sa");
	else if (op == SB)
		ft_putendl("sb");
	else if (op == SS)
		ft_putendl("ss");
	else if (op == PA)
		ft_putendl("pa");
	else if (op == PB)
		ft_putendl("pb");
	else if (op == RA)
		ft_putendl("ra");
	else if (op == RB)
		ft_putendl("rb");
	else if (op == RR)
		ft_putendl("rr");
	else if (op == RRA)
		ft_putendl("rra");
	else if (op == RRB)
		ft_putendl("rrb");
	else if (op == RRR)
		ft_putendl("rrr");
	display_color(stack, 0);
}

void	do_operation(t_stack *stack, char op)
{
	run_op(stack, op);
	stack->bonus.moves++;
	print_op(stack, op);
}

void	proceed_op(t_stack *stack, char op)
{
	t_op	*tmp;

	if (op)
	{
		run_op(stack, op);
		store_op(stack, op);
	}
	else
	{
		stack->moves = 0;
		delete_op(stack->op);
		replace_op(stack->op);
		tmp = *stack->op;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			if (stack->bonus.stacks)
				run_op(stack, tmp->op);
			print_op(stack, tmp->op);
			tmp = tmp->next;
			stack->bonus.moves++;
		}
	}
}

void	sort_stack(t_stack *stack)
{
	if (is_sorted(stack->stack_a, stack->len_a, 0, 1))
		return ;
	stack->moves = 0;
	if (stack->param <= 5)
	{
		simple_sort(stack);
	}
	else
	{
		quick_sort(stack);//
		if (stack->bonus.debug)
			init_stack_a(stack); //
		proceed_op(stack, NONE); //
	}
	if (stack->bonus.count)
		display_total(stack);
}
