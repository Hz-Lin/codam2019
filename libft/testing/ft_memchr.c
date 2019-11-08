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
#include <stdio.h>

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

// int		main(void)
// {
// 	const char	str[] = "this is just a test";
// 	const char	ch = 'j';
// 	const char	str0[] = "this is just a test";
// 	char		*ret;

// 	ret = memchr(str, ch, strlen(str));
// 	printf("%s\n", ret);
// 	ret = ft_memchr(str0, ch, strlen(str0));
// 	printf("%s\n", ret);
// 	return (0);
// }
