/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_env.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 22:57:48 by hlin          #+#    #+#                 */
/*   Updated: 2020/11/05 23:16:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		init_env(t_shell *mshell)
{
	extern char		**env_var;
	t_var			*env;
	int				i;

	//init_env_head(mshell);
	i = 1;
	env = mshell->env;
	while (env_var[i])
	{
		env->next = ?init_var(env_var[i]);
		if (!env->next)
			return (clear_env?)
		env = env->next;
		i++;
	}
	mshell->envp = convert_env(mshell ->env);
	if (!mshell->envp)
		return (clear_env?)
	return (1);
}
