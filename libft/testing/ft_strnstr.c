/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 11:05:56 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/04 11:05:59 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*s;
	size_t	nlen;

	s = (char*)haystack;
	nlen = ft_strlen(needle);
	if (nlen == 0)
		return (s);
	if (ft_strlen(haystack) == 0)
		return (NULL);
	while (*s && len > 0 && len >= nlen)
	{
		if (ft_strncmp(s, needle, nlen) == 0)
		{
			return (s);
		}
		s++;
		len--;
	}
	return (NULL);
}

// int		main(void)
// {
// 	const char	*src;
// 	const char	*needle;
// 	char		*res;

// 	src = "AAAAAAAAAAAAA";
// 	needle = "AAAAAAAAAAAAA";
// 	res = strnstr(src, needle, ft_strlen(src));
// 	printf("%s\n", res);
// 	res = ft_strnstr(src, needle, ft_strlen(src));
// 	printf("%s\n", res);
// }
