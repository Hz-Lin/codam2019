/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   proceed_op_delete.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 12:28:00 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/22 15:04:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	need_delete(int	op1, int op2)
{
	if ((op1 == PA && op2 == PB) || (op1 == PB && op2 == PA))
		return (1);
	else if ((op1 == RA && op2 == RRA) || (op1 == RRA && op2 == RA))
		return (1);
	else if ((op1 == RB && op2 == RRB) || (op1 == RRB && op2 == RB))
		return (1);
	return (0);
}

static void	do_delete(t_op **op, t_op *tmp, t_op *tmp2)
{
	if (tmp2->prev && tmp->next)
	{
		tmp2->prev->next = tmp->next;
		tmp->next->prev = tmp2->prev;
		free(tmp);
	}
	else if (tmp2->prev)
	{
		tmp2->prev->next = NULL;
		free(tmp);
		*op = tmp2->prev;
	}
	else if (tmp->next)
	{
		tmp->next->prev = NULL;
		free(tmp);
		*op = tmp->next;
	}
}

void	delete_ops(t_op **op)
{
	t_rm	rm;

	rm.doit = 0;
	if (*op)
	{
		rm.tmp = *op;
		while (rm.tmp && rm.tmp->prev)
		{
			rm.tmp2 = rm.tmp->prev;
			if (need_delete(rm.tmp->op, rm.tmp2->op))
			{
				rm.doit = 1;
				do_delete(op, rm.tmp, rm.tmp2);
			}
			if (rm.doit)
			{
				rm.tmp = *op;
				rm.doit = 0;
				free(rm.tmp2);
			}
			else
				rm.tmp = rm.tmp2;
		}
		*op = rm.tmp;
	}
}
