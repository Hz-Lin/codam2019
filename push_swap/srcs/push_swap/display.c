/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 20:23:25 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/22 16:26:35 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	set_color(t_stack *stack, char *color)
{
	if (!stack->bonus.colors)
		return ;
	else
	{
		if (ft_strequ(color, "RED"))
			ft_putstr_fd("\033[0;31m", 1);
		else if (ft_strequ(color, "GREEN"))
			ft_putstr_fd("\033[0;32m", 1);
		else if (ft_strequ(color, "YELLOW"))
			ft_putstr_fd("\033[0;33m", 1);
		else if (ft_strequ(color, "BLUE"))
			ft_putstr_fd("\033[0;34m", 1);
		else if (ft_strequ(color, "PURPLE"))
			ft_putstr_fd("\033[0;35m", 1);
		else if (ft_strequ(color, "CYAN"))
			ft_putstr_fd("\033[0;36m", 1);
		else if (ft_strequ(color, "RESET"))
			ft_putstr_fd("\033[0m", 1);
	}
}

static void	display_stacks(t_stack *stack)
{
	int	i;

	i = 0;
	set_color(stack, "CYAN");
	ft_putstr_fd("->A: ", 1);
	while (i < stack->len_a)
	{
		if (i + 1 == stack->len_a)
			ft_printf("%d", stack->stack_a[i]);
		else
			ft_printf("%d, ", stack->stack_a[i]);
		i++;
	}
	ft_putstr_fd("\n->B: ", 1);
	i = 0;
	while (i < stack->len_b)
	{
		if (i + 1 == stack->len_b)
			ft_printf("%d", stack->stack_b[i]);
		else
			ft_printf("%d, ", stack->stack_b[i]);
		i++;
	}
	ft_putstr_fd("\n", 1);
	set_color(stack, "RESET");
}

static void	display_color(t_stack *stack, char begin)
{
	if (begin)
	{
		if (stack->bonus.colors)
			set_color(stack, "BLUE");
	}
	else
	{
		if (stack->bonus.colors)
			set_color(stack, "RESET");
		if (stack->bonus.debug)
			display_stacks(stack);
	}
}

void	display_total(t_stack *stack)
{
	if (stack->bonus.colors)
		set_color(stack, "PURPLE");
	ft_printf("\nTotal sorting moves: %d\n", stack->bonus.moves);
	if (stack->bonus.colors)
		set_color(stack, "RESET");
}

void	print_op(t_stack *stack, char op)
{
	display_color(stack, 1);
	if (op == SA)
		ft_putendl_fd("sa", 1);
	else if (op == SB)
		ft_putendl_fd("sb", 1);
	else if (op == SS)
		ft_putendl_fd("ss", 1);
	else if (op == PA)
		ft_putendl_fd("pa", 1);
	else if (op == PB)
		ft_putendl_fd("pb", 1);
	else if (op == RA)
		ft_putendl_fd("ra", 1);
	else if (op == RB)
		ft_putendl_fd("rb", 1);
	else if (op == RR)
		ft_putendl_fd("rr", 1);
	else if (op == RRA)
		ft_putendl_fd("rra", 1);
	else if (op == RRB)
		ft_putendl_fd("rrb", 1);
	else if (op == RRR)
		ft_putendl_fd("rrr", 1);
	display_color(stack, 0);
}
