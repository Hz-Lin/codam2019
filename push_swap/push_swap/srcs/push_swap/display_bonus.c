/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_bonus.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 20:23:25 by hlin          #+#    #+#                 */
/*   Updated: 2021/05/05 16:06:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static void	print_stack_array(int *array, int arr_size)
// {
// 	int	i;

// 	i = 0;
// 	while (i < arr_size)
// 	{
// 		if (i + 1 == arr_size)
// 		{
// 			ft_putnbr_fd(array[i], 1);
// 		}
// 		else
// 		{
// 			ft_putnbr_fd(array[i], 1);
// 			ft_putstr_fd(", ", 1);
// 		}
// 		i++;
// 	}
// }

// static void	display_stacks(t_stack *stack)
// {
// 	set_color(stack, "CYAN");
// 	ft_putstr_fd("->A: ", 1);
// 	print_stack_array(stack->stack_a, stack->len_a);
// 	ft_putstr_fd("\n", 1);
// 	ft_putstr_fd("->B: ", 1);
// 	print_stack_array(stack->stack_b, stack->len_b);
// 	ft_putstr_fd("\n", 1);
// 	set_color(stack, "RESET");
// }

void	display_stacks(t_stack *stack)
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
	ft_putstr_fd("\n->B", 1);
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

void	set_color(t_stack *stack, char *color)
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

void	display_color(t_stack *stack, char begin)
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
