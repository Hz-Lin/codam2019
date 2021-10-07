/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 16:08:19 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/29 17:01:21 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/srcs/libft.h"
# include "../libft/ft_printf/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** define instructions
*/
typedef enum s_instr
{
	NONE,
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}				t_instr;

typedef struct s_op
{
	char		op;
	int			i;
	struct s_op	*prev;
	struct s_op	*next;
}				t_op;

typedef struct s_display
{
	int				*stack;
	char			debug;
	char			colors;
	char			count;
	int				moves;
	int				flags;
}					t_display;

typedef struct s_stack
{
	int				*stack_a;
	int				*stack_b;
	int				*tab_med;
	int				tab_med_i;
	int				param;
	int				len_a;
	int				len_b;
	char			op_ok;
	int				med;
	int				is_med;
	int				med_pushed;
	int				dist;
	int				min;
	int				max;
	char			first_round;
	t_op			**op;
	int				moves;
	char			display_stacks;
	t_display		bonus;
}					t_stack;

typedef struct s_rm
{
	t_op			*tmp;
	t_op			*tmp2;
	int				doit;
}					t_rm;

/*
** PUSH_SWAP
*/
int					ft_end(int status);
int					find_dup(t_stack stack);
int					is_sorted(int *array, int len, int start, int inc);
int					check_args(char **arg);
void				do_operation(t_stack *stack, char op);

void				parse_display(char **argv, t_display *dsp);

void				display_total(t_stack *stack);
void				print_op(t_stack *stack, char op);

void				run_op(t_stack *stack, char op);

void				delete_ops(t_op **op);
void				replace_ops(t_op **op);

void				proceed_op(t_stack *stack, char op);
void				sort_stack(t_stack *stack);

void				simple_sort(t_stack *stack);
void				quick_sort(t_stack *stack);

int					find_target(int *array, int len, int med, char comp);
void				split_a(t_stack *s, int *array);
void				split_b(t_stack *s, int *array);

int					get_min(int *array, int len);
int					get_max(int *array, int len);
int					find_max_pos(int *array, int len);
int					get_med(int *array, int len);
int					get_next_med(t_stack *stack, int *array, int size);
int					get_dist_to_med(int *array, int size, int next_med);

/*
** CHECKER
*/
int					checker_operations(char *line, t_stack *stack);

#endif
