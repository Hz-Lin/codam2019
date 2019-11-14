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

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	char	*s;
	int		pos;
	int		nlen;
	int		slen;

	s = (char*)str;
	pos = 0;
	nlen = (int)ft_strlen(needle);
	slen = (int)ft_strlen(str);
	printf("nlen: %d  slen: %d \n", nlen, slen);
	if (*needle == '\0')
		return (s);
	if (*str == '\0')
		return (NULL);
	printf("(slen - nlen): %d  (len - nlen): %d \n", (slen - nlen), ((int)len - nlen));
	while (pos <= (slen - nlen) && pos <= ((int)len - nlen))
	{
		// printf("s: %s", (s + pos));
		// printf("pos: %d  cmp: %d \n", pos, ft_strncmp((s + pos), needle, nlen));
		if (ft_strncmp((s + pos), needle, nlen) == 0)
		{
			printf("pos: %d\n", pos);
			return (s + pos);
		}
		pos++;
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
