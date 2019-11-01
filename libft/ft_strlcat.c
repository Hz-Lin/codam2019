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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	len_orgdst;
	unsigned int	len_src;

	i = 0;
	len_orgdst = ft_strlen(dst);
	len_src = ft_strlen(src);
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
