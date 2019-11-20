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
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	while (*(dst + i) != '\0' && i < dstsize)
		i++;
	len_dst = i;
	if (dstsize != 0)
	{
		while (*(src + i - len_dst) && i < (dstsize - 1))
		{
			*(dst + i) = *(src + i - len_dst);
			i++;
		}
	}
	if (len_dst < dstsize)
		*(dst + i) = '\0';
	return (len_dst + ft_strlen(src));
}

/* war test */
void	ft_print_result(int n)
{
	char c;

	if (n >= 10)
		ft_print_result(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

int		main(void)
{
	char	*dest;

	if (!(dest = (char *)malloc(sizeof(*dest) * 15)))
		return (0);
	memset(dest, 0, 15);
	memset(dest, 'r', 6);

	/* test08 */
	dest[10] = 'a';
	ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
	write(1, "\n", 1);
	write(1, dest, 15);
}
