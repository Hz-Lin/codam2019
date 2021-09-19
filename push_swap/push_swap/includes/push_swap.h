/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/16 16:08:19 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/14 16:30:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/srcs/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

/*
** define instructions
*/
typedef enum s_instr
{
	NONE, SA, SB, SS, PA, PB, RA, RB, RR, RRA, RRB, RRR
}				t_instr;

// typedef enum s_color
// {
// 	A = 0, B, AB
// }				t_color;

typedef struct s_op
{
	char		op;
	int			i;
	struct s_op	*prev;
	struct s_op	*next;
}				t_op;

typedef struct		s_display
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

// /*
// ** CHECKER
// */
// int					is_sorted(int *array, int len, int start, int increase);
// int					get_operations(char *line, t_stack *stack);

/*
** PUSH_SWAP
*/
int					ft_end(int status);
int					check_args(char **arg);
int					find_dup(t_stack stack);

void				parse_display(char **argv, t_display *dsp);

void				run_op(t_stack *stack, char op);
void				do_operation(t_stack *stack, char op);
void				proceed_op(t_stack *stack, char op);

int					get_min(int *array, int len);
int					get_max(int *array, int len);
int 				find_max_pos(int *array, int len);

void				sort_stack(t_stack *stack);
void				simple_sort(t_stack *stack);

void				set_color(t_stack *stack, char *color);
void				display_stacks(t_stack *stack);
void				display_color(t_stack *stack, char begin);
void				display_total(t_stack *stack);


#endif
