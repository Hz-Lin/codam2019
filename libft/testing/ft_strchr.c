/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 16:21:34 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/01 16:21:41 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char*)s);
}

// int		main(void)
// {
// 	const char	*str3;
// 	char		c;
// 	char		*res;

// 	c = '\0';
// 	str3 = "there is so \0ma\0ny \0 \\0 in t\0his stri\0ng !\0\0\0\0";
// 	res = ft_strchr(str3, c);
// 	printf("%s\n", res);
// 	res = strchr(str3, c);
// 	printf("%s\n", res);
// }
