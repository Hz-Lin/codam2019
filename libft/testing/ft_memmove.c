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
#include <stdio.h>

void	*memcopy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	while (n > 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;
	size_t			i;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	i = 0;
	if (ptr_src < ptr_dst)
	{
		while (i < len)
		{
			ptr_dst[len - i] = ptr_src[len - i];
			i++;
		}
	}
	else
	{
		memcopy(dst, src, len);
		// while (len > 0)
		// {
		// 	*ptr_dst = *ptr_src;
		// 	len--;
		// 	ptr_dst++;
		// 	ptr_src++;
		// }
	}
	return (dst);
}

// int		main (void)
// {
// 	char dest[] = "strdest";
// 	const char src[]  = "strsrc";
// 	char dest0[] = "strdest";
// 	const char src0[]  = "strsrc";

// 	printf("Before memmove dest = %s, src = %s\n", dest, src);
// 	memmove(dest, src, 8);
// 	printf("After memmove dest = %s, src = %s\n", dest, src);
// 	printf("Before ft_memmove dest = %s, src = %s\n", dest0, src0);
// 	ft_memmove(dest0, src0, 8);
// 	printf("After ft_memmove dest = %s, src = %s\n", dest0, src0);
// 	return (0);
// }
