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

#include <string.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

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

int		main(void)
{
	char	dst1[50] = "I am ";
	char	src1[10] = "Jan";
	char	dst2[50] = "I am ";
	char	src2[10] = "Jan";
	int		src_len;

	src_len = ft_strlcat(dst1, src1, 10);
	printf("result of ft_strlcat: %d %s\n", src_len, dst1);
	src_len = strlcat(dst2, src2, 10);
	printf("result of strlcat: %d %s\n", src_len, dst2);
}
