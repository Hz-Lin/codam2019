/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 17:18:26 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 17:18:28 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	uc;

	i = 0;
	ptr = (unsigned char*)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (*ptr == (unsigned char)c)
		{
			return ((void*)ptr++);
		}
		ptr++;
		i++;
	}
	return (NULL);
}
