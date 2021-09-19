/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_utils.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/09/14 16:27:18 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/14 16:36:24 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

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
			if (((r.tmp->op == PA && r.tmp2->op == PB) ||
						(r.tmp->op == PB && r.tmp2->op == PA)) && (r.doit = 1))
				delete(op, r.tmp, r.tmp2);
			else if (((r.tmp->op == RA && r.tmp2->op == RRA) ||
						(r.tmp->op == RRA && r.tmp2->op == RA)) && (r.doit = 1))
				delete(op, r.tmp, r.tmp2);
			else if (((r.tmp->op == RB && r.tmp2->op == RRB) ||
						(r.tmp->op == RRB && r.tmp2->op == RB)) && (r.doit = 1))
				delete(op, r.tmp, r.tmp2);
			if (r.doit)
				doit(op, &r, 1);
			else
				r.tmp = r.tmp2;
		}
		*op = r.tmp;
		}
	}
}
