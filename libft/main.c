/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:27:29 by hlin          #+#    #+#                 */
/*   Updated: 2019/10/29 11:27:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[50] = "This is string.h library function";
	char	dst[10];
	char	dst1[50] = "I am ";
	char	src1[10] = "Jan";
	int		src_len;

	// printf("result of ft_strlen: %lu\n", ft_strlen(str));
	// printf("result of strlen: %lu\n", strlen(str));
	// src_len = ft_strlcpy(dst, str, 10);
	// printf("result of ft_strlcpy: %d %s\n", src_len, dst);
	// src_len = strlcpy(dst, str, 10);
	// printf("result of strlcpy: %d %s\n", src_len, dst);
	src_len = ft_strlcat(dst1, src1, 2);
	printf("result of ft_strlcat: %d %s\n", src_len, dst1);
	src_len = strlcat(dst1, src1, 2);
	printf("result of strlcat: %d %s\n", src_len, dst1);
}
