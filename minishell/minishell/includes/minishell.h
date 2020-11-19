/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   minishell.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 18:12:53 by hlin          #+#    #+#                 */
/*   Updated: 2020/11/06 11:23:18 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

typedef struct		s_vec
{
	char			*data;
	size_t			type_size;
	size_t			capacity;
	size_t			index;
}					t_vec;

typedef struct		s_cmd
{
	char			**args;
	int				*argtypes;
	int				cmdtype;
	// int				iostream[2];
	// int				cmdpipe[2];
	struct s_cmd	*next;
}					t_cmd;

typedef struct		s_var
{
	char			*name;
	char			*value;
	size_t			len;
	struct s_var	*next;
}					t_var;

typedef struct		s_shell
{
	t_vec			files;
	t_vec			arg_types;
	t_vec			args;
	size_t			argc;
	t_cmd			*commands;
	int				exit_status;
	char			**envp;
	t_var			*env;
	//t_line			line;?
}					t_shell;

#endif
