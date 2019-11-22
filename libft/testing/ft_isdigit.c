/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isdigit.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:30:11 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 13:30:14 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '\n';
// 	printf("%d\n", isdigit(c));
// 	printf("%d\n", ft_isdigit(c));
// }
