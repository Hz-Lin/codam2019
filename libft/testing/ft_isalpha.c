/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 12:11:28 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 12:11:30 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <ctype.h>
#include <stdio.h>

int	ft_isalpha(int c)
{
	int	res;

	res = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		res = 1;
	}
	return (res);
}

// int	main(void)
// {
// 	char	c;

// 	c = ' ';
// 	printf("%d\n", isalpha(c));
// 	printf("%d\n", ft_isalpha(c));
// }
