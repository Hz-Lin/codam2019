/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 13:41:15 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 13:41:22 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isalnum(int c)
{
	int	res;

	res = 0;
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		res = 1;
	}
	else if (c >= '0' && c <= '9')
	{
		res = 1;
	}
	return (res);
}

int	main(void)
{
	char	c;

	c = 'Z';
	printf("%d\n", isalnum(c));
	printf("%d\n", isalnum(c));
}
