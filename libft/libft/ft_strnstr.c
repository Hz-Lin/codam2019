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

int		str_compare(const char *str, const char *needle, int pos)
{
	int		res;
	int		i;
	int		needle_len;

	res = 1;
	i = 0;
	needle_len = ft_strlen(needle);
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
