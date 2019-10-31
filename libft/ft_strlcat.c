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
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	i;
	const char		*org_dst;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	org_dst = dst;
	i = 0;
	if (size < len_dst)
	{
		while (i < size - 1)
		{
			dst[i] = org_dst[i];
			i++;
		}
		dst[i] = '\0';
		return (size + len_src);
	}
	else
	{
		while (i + len_dst < size - 1)
		{
			dst[i + len_dst] = src[i];
			i++;
		}
		dst[i + len_dst] = '\0';
		return (len_dst + len_src);
	}
}
