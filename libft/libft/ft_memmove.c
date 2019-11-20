/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 16:01:25 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 16:01:29 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	i = 0;
	if (ptr_src == NULL && ptr_src == ptr_dst)
		return (dst);
	if (ptr_src < ptr_dst)
		while (i < n)
		{
			i++;
			ptr_dst[n - i] = ptr_src[n - i];
		}
	else
		while (n > 0)
		{
			*(ptr_dst) = *(ptr_src);
			ptr_dst++;
			ptr_src++;
			n--;
		}
	return (dst);
}
