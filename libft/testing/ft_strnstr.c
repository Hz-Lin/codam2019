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

size_t	cal_strlen(const char *s)
{
	int		len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

int		str_compare(const char *str, const char *needle, int pos)
{
	int		res;
	int		i;
	int		needle_len;

	res = 1;
	i = 0;
	needle_len = cal_strlen(needle);
	while (i < needle_len)
	{
		if (str[pos + i] != needle[i])
		{
			res = 0;
		}
		i++;
	}
	return (res);
}

char	*ft_strnstr(const char *str, const char *needle, size_t len)
{
	char			*res;
	char			*ptr;
	unsigned int	pos;
	unsigned int	needle_len;

	needle_len = cal_strlen(needle);
	res = NULL;
	ptr = (char*)str;
	if (needle_len == 0)
	{
		return (ptr);
	}
	pos = 0;
	while (pos < len - needle_len && pos < cal_strlen(str) - needle_len)
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

// int		main(void)
// {
// 	const char	*src;
// 	const char	*needle;
// 	char		*res;

// 	src = "The one ring to rule them all or kill them all, end";
// 	needle = "them";
// 	res = strnstr(src, needle, 24);
// 	printf("%s\n", res);
// 	res = ft_strnstr(src, needle, 24);
// 	printf("%s\n", res);
// }
