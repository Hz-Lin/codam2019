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

char	*ft_strchr(const char *str, int c)
{
	while (*str != c)
	{
		if (*str == '\0')
		{
			return (NULL);
		}
		str++;
	}
	return ((char*)str);
}

// int		main(void)
// {
// 	const char	*str3;
// 	char		c;
// 	char		*res;

// 	c = 'a';
// 	str3 = "hello every! Mr.x is here";
// 	res = ft_strchr(str3, c);
// 	printf("%s\n", res);
// 	res = strchr(str3, c);
// 	printf("%s\n", res);
// }
