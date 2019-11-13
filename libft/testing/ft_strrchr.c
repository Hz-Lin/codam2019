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

char	*ft_strrchr(const char *str, int ch)
{
	char	*res;
	char	*s;
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	s = (char*)str;
	while (i <= ft_strlen(str))
	{
		if (s[i] == (char)ch)
		{
			res = &s[i];
			count++;
		}
		i++;
	}
	if (count != 0)
		return (res);
	return (NULL);
}

// int		main(void)
// {
// 	const char	*str3;
// 	char		c;
// 	char		*res;

// 	c = '\0';
// 	str3 = "One ring to rule them all";
// 	res = ft_strrchr(str3, c);
// 	printf("%s\n", res);
// 	res = strrchr(str3, c);
// 	printf("%s\n", res);
// }
