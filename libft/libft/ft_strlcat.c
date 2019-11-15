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
	size_t	i;
	size_t	len_dst;

	i = 0;
	if (dst == NULL && size == 0)
		return (ft_strlen(src));
	while (*(dst + i) != '\0' && i < size)
		i++;
	len_dst = i;
	if (size != 0)
	{
		while (*(src + i - len_dst) && i < (size - 1))
		{
			*(dst + i) = *(src + i - len_dst);
			i++;
		}
	}
	if (len_dst < size)
		*(dst + i) = '\0';
	return (len_dst + ft_strlen(src));
}
