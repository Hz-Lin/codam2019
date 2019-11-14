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
	if (*needle == '\0')
		return (s);
	if (*str == '\0')
		return (NULL);
	while (pos <= (slen - nlen) && pos <= ((int)len - nlen))
	{
		if (ft_strncmp((s + pos), needle, nlen) == 0)
		{
			return (s + pos);
		}
		pos++;
	}
	return (NULL);
}
