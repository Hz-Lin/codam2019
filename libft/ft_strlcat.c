/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/30 18:00:35 by hlin          #+#    #+#                 */
/*   Updated: 2019/10/30 18:00:38 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	cal_len(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_orgdst;
	unsigned int	len_src;

	i = 0;
	len_orgdst = cal_len(dst);
	len_src = cal_len(src);
	if (size < len_orgdst)
	{
		return (size + len_src);
	}
	else
	{
		while (i < size - 1 && i < (len_orgdst + len_src))
		{
			if (i >= len_orgdst)
			{
				dst[i] = src[i - len_orgdst];
			}
			i++;
		}
		dst[i] = '\0';
		return (len_orgdst + len_src);
	}
}
