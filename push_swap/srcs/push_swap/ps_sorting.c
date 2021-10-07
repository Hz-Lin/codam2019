/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ps_sorting.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 12:08:54 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/22 15:58:57 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_stack_a(t_stack *e)
{
	int			i;

	i = 0;
	while (i < e->param)
	{
		e->stack_a[i] = e->bonus.stack[i];
		i++;
	}
}

static void	create_newlink(t_op **op, t_op *new)
{
	new->prev = *op;
	(*op)->next = new;
	*op = new;
}

static void	store_op(t_stack *stack, char op)
{
	t_op	*new;

	new = (t_op *)ft_memalloc(sizeof(t_op));
	if (!new)
		exit(ft_end(4));
	new->op = op;
	new->i = stack->moves;
	if (*stack->op)
		create_newlink(stack->op, new);
	else
		*stack->op = new;
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
		delete_ops(stack->op);
		replace_ops(stack->op);
		tmp = *stack->op;
		while (tmp->prev)
			tmp = tmp->prev;
		while (tmp)
		{
			if (stack->bonus.stack)
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
		quick_sort(stack);
		if (stack->bonus.debug)
			init_stack_a(stack);
		proceed_op(stack, NONE);
	}
	if (stack->bonus.count)
		display_total(stack);
}
