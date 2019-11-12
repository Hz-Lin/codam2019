/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:26:36 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 13:26:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (len == 0 || !s)
	{
		return (NULL);
	}
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int		main(void)
// {
// 	char const	*str;
// 	char		*res;
// 	char const *s;
	
// 	str = "Precious! My precious! Where is my precious?";
// 	res = ft_substr(str, 10, 12);
// 	printf("%s\n", res);
// 	s = "split  ||this|for|me|||||!|";
// 	printf("%s\n", ft_substr(s, 0, 6));
// 	return (0);
// }
