/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:55:52 by hlin          #+#    #+#                 */
/*   Updated: 2019/10/29 13:55:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = 0;
	i = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	i = 0;
	while (src[i] != '\0' && i < src_len && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int		main(void)
// {
// 	char	str[50] = "This is string.h library function";
// 	char	dst[10];
// 	int		src_len;

// 	src_len = ft_strlcpy(dst, str, 10);
// 	printf("result of ft_strlcpy: %d %s\n", src_len, dst);
// 	src_len = strlcpy(dst, str, 10);
// 	printf("result of strlcpy: %d %s\n", src_len, dst);
// }
