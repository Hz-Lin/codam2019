/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putendl_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 14:56:54 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/11 14:56:57 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	unsigned int	i;

	i = 0;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

// int		main(void)
// {
// 	char	*s;

// 	s = "one ring to rule them all";
// 	ft_putendl_fd(s, 1);
// 	return (0);
// }
