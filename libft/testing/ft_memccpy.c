/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 14:58:48 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 14:58:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr_dst;
	unsigned char	*ptr_src;

	i = 0;
	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	while (i < n)
	{
		ptr_dst[i] = ptr_src[i];
		if (ptr_src[i] == (unsigned char)c)
		{
			return ((void*)(dst + i + 1));
		}
		i++;
	}
	return (NULL);
}

// int		main(void)
// {
// 	char	string1[60] = "Taj Mahal is a historic monument in India.";
// 	char	dst1[61];
// 	char	string2[60] = "Taj Mahal is a historic monument in India.";
// 	char	dst2[61];
// 	char	*res;

// 	res = memccpy(dst1, string1, 'c', 42);
// 	printf("res: %s\n", res);
// 	printf("dst: %s\n", dst1);
// 	res = ft_memccpy(dst2, string2, 'c', 42);
// 	printf("res: %s\n", res);
// 	printf("dst: %s\n", dst2);
// 	return (0);
// }
