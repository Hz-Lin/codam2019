/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 17:55:37 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/01 17:55:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	char	ch;
	char	*pos;

	ch = c;
	pos = NULL;
	while (*str != '\0')
	{
		if (*str == c)
		{
			pos = (char*)str;
		}
		str++;
	}
	return (pos);
}

// int		main(void)
// {
// 	const char	*str3;
// 	char		c;
// 	char		*res;

// 	c = 'a';
// 	str3 = "hello every! Mr.x is here";
// 	res = ft_strrchr(str3, c);
// 	printf("%s\n", res);
// 	res = strrchr(str3, c);
// 	printf("%s\n", res);
// }
