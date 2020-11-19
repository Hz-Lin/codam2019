/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 18:10:01 by hlin          #+#    #+#                 */
/*   Updated: 2020/11/05 22:57:11 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		main(void)
{
	t_shell		mshell;

	//signal functions?
	if (!init_env(&mshell))
		return (1);
	if (!set_pwd(&mshell.env))
		return (1);
	//inital readline, input token etc...
	return (0);
}
