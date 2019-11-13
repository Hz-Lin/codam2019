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

int		str_compare(const char *str, const char *needle, int pos)
{
	unsigned int	i;
	unsigned int	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len > (ft_strlen(str) - pos))
		return (0);
	while (i < needle_len)
	{
		if (str[pos + i] != needle[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	char			*res;
	char			*ptr;
	unsigned int	pos;
	unsigned int	needle_len;

	needle_len = ft_strlen(needle);
	res = NULL;
	ptr = (char*)str;
	if (needle_len == 0)
	{
		return (ptr);
	}
	pos = 0;
	while (pos < len - needle_len && pos < ft_strlen(str) - needle_len)
	{
		if (str_compare(str, needle, pos))
		{
			res = ptr;
			return (res);
		}
		pos++;
		ptr++;
	}
	return (res);
}

int		main(void)
{
	const char	*src;
	const char	*needle;
	char		*res;

	src = "abcdef";
	needle = "abcdefghijklmnop";
	res = strnstr(src, needle, 24);
	printf("%s\n", res);
	res = ft_strnstr(src, needle, 24);
	printf("%s\n", res);
}
