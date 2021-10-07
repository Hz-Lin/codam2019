/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   procced_op_replace.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/21 14:38:46 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/22 15:04:15 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	need_replace(int op1, int op2)
{
	if ((op1 == RA && op2 == RB) || (op1 == RB && op2 == RA))
		return (RR);
	else if ((op1 == RRA && op2 == RRB) || (op1 == RRB && op2 == RRA))
		return (RRR);
	else if ((op1 == SA && op2 == SB) || (op1 == SB && op2 == SA))
		return (SS);
	return (0);
}

static void	do_replace(t_op *tmp, t_op *tmp2, char op)
{
	tmp2->prev = tmp->prev;
	if (tmp->prev)
		tmp->prev->next = tmp2;
	tmp2->op = op;
	free(tmp);
}

void	replace_ops(t_op **op)
{
	t_rm		rm;
	int			new_op;

	rm.doit = 0;
	if (*op)
	{
		rm.tmp = *op;
		while (rm.tmp && rm.tmp->next)
		{
			rm.tmp2 = rm.tmp->next;
			new_op = need_replace(rm.tmp->op, rm.tmp2->op);
			if (new_op)
			{
				rm.doit = 1;
				do_replace(rm.tmp, rm.tmp2, new_op);
			}
			if (rm.doit)
			{
				rm.tmp = *op;
				rm.doit = 0;
			}
			else
				rm.tmp = rm.tmp2;
		}
	}
}
