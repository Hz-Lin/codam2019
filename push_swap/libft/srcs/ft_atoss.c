/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoss.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/05 21:58:29 by hlin          #+#    #+#                 */
/*   Updated: 2021/04/05 23:53:44 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_atoss(const char *str)
{
	int		s;
	ssize_t	ret;

	s = 1;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return (s * ret);
}
