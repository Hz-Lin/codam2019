/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 17:42:38 by hlin          #+#    #+#                 */
/*   Updated: 2021/04/06 23:26:08 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	get_instruction(t_stack *stack)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (!line)
			exit(ft_end(3));
		stack->op_ok = 0;
		if (!get_operations(line, stack))
			exit(ft_end(1));
		free(line);
	}
}

static void	initial_stack(char **arg, int param, t_stack *stack)
{
	stack->param = param;
	stack->stack_a = ft_memalloc(sizeof(int) * stack->param);
	stack->stack_b = ft_memalloc(sizeof(int) * stack->param);
	if (!stack->stack_a || !stack->stack_b)
		exit(ft_end(4));
	stack->len_a = stack->param;
	stack->len_b = 0;
}

static void	checker(char **arg, int param)
{
	int		i;
	t_stack	stack;

	i = 0;
	initial_stack(arg, param, &stack);
	while (arg[i])
	{
		stack.stack_a[i] = ft_atoi(arg[i]);
		free(arg[i]);
		i++;
	}
	free(arg);
	if (find_dup(stack))
		exit(ft_end(1));
	get_instruction(&stack);
	if (is_sorted(stack.stack_a, stack.len_a, 0, 1) && stack.len_b == 0)
		exit(ft_end(0));
	else
		exit(ft_end(2));
}

static char	**get_arg(int argc, char **argv)
{
	int		i;
	char	**arg;

	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		arg = (char **)malloc(sizeof(char *) * argc);
		if (!arg)
			exit(ft_end(4));
		i = 0;
		while (i + 1 < argc)
		{
			arg[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		arg[i] = NULL;
	}
	return (arg);
}

int	main(int argc, char **argv)
{
	char	**arg;
	int		param;

	if (argc < 2)
		return (-1);
	else
		arg = get_arg(argc, argv);
	param = check_args(arg);
	if (!param)
		exit(ft_end(1));
	checker(arg, param);
	return (0);
}
