/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:25:01 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 14:25:03 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	if (dst == src)
		return (dst);
	while (n > 0)
	{
		*ptr_dst = *ptr_src;
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return (dst);
}

int		main(void)
{
	const char src[50] = "This is a function from libft";
	char dest[50] = "Hello world";
	const char src0[50] = "This is a function from libft";
	char dest0[50] = "Hello world";

	printf("Before memcpy dest = %s\n", dest);
	memcpy(dest, src, strlen(src)+1);
	printf("After memcpy dest = %s\n", dest);
	printf("Before ft_memcpy dest = %s\n", dest0);
	ft_memcpy(dest0, src0, strlen(src0)+1);
	printf("After ft_memcpy dest = %s\n", dest0);
	return(0);
}
