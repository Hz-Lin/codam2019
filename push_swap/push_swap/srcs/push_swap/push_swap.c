/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 22:17:57 by hlin          #+#    #+#                 */
/*   Updated: 2021/07/28 22:29:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	initial_stack(char **arg, int param, t_stack *stack, t_display dsp)
{
	stack->bonus = dsp;
	stack->param = param;
	stack->stack_a = ft_memalloc(sizeof(int) * stack->param);
	stack->stack_b = ft_memalloc(sizeof(int) * stack->param);
	stack->bonus.stack = ft_memalloc(sizeof(int) * stack->param);
	if (!stack->stack_a || !stack->stack_b || !stack->bonus.stack)
		exit(ft_end(4));
	stack->len_a = stack->param;
	stack->len_b = 0;
	stack->op = (t_op **)ft_memalloc(sizeof(t_op *));
	if (!stack->op)
		exit(ft_end(4));
}

static void	push_swap(char **arg, int param, t_display dsp)
{
	int		i;
	t_stack	stack;

	i = 0;
	initial_stack(arg, param, &stack, dsp);
	while (arg[i])
	{
		stack.stack_a[i] = ft_atoi(arg[i]);
		stack.bonus.stack[i] = ft_atoi(arg[i]);
		free(arg[i]);
		i++;
	}
	free(arg);
	if (find_dup(stack))
		exit(ft_end(1));
	sort_stack(&stack);
	exit(ft_end(10));
}

static char	**get_arg(int argc, char **argv, int flags_num)
{
	int		i;
	char	**arg;

	if (argc == 2 + flags_num)
		arg = ft_split(argv[1 + flags_num], ' ');
	else
	{
		arg = (char **)malloc(sizeof(char *) * (argc - flags_num));
		if (!arg)
			exit(ft_end(4));
		i = 0;
		while (i + 1 + flags_num < argc)
		{
			arg[i] = ft_strdup(argv[i + 1 + flags_num]);
			i++;
		}
		arg[i] = NULL;
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	char		**arg;
	int			i;
	int			param;
	t_display	dsp;

	if (argc < 2)
		return (-1);
	parse_display(argv, &dsp);
	arg = get_arg(argc, argv, dsp.flags);
	param = check_args(arg);
	if (!param)
		exit(ft_end(1));
	push_swap(arg, param, dsp);
	return (0);
}
