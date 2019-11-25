/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 17:47:26 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/08 17:47:28 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	i = 0;
	if (!s)
	{
		// printf("%s\n", "failed here");
		return (NULL);
	}
	res = (char*)malloc((sizeof(*res) * (ft_strlen(s) + 1)));
	if (!res)
	{
		// printf("%s\n", "failed here");
		return (NULL);
	}
	while (s[i] != '\0')
	{
		res[i] = f(i, s[i]);
		// printf("%c\n", f(i, s[i]));
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char	ft_test(unsigned int i, char c)
// {
// 	char	res;

// 	res = ((c - '0') * i % 10) + '0';
// 	return (res);
// }

// int		main(void)
// {
// 	char const		*str;
// 	char			*res;

// 	str = "123456";
// 	res = ft_strmapi(str, ft_test);
// 	printf("%s\n", res);
// 	return (0);
// }
