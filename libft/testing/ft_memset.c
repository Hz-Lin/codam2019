/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:29:52 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 11:29:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char*)b;
	i = 0;
	if (len == 0)
	{
		return (b);
	}
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}

// int		main(void)
// {
// 	char str0[50] = "This is string.h library function";
// 	char str1[50] = "This is string.h library function";

// 	memset(str0, '$', 7);
// 	printf("%s\n", str0);
// 	ft_memset(str0 + 4, 'x', 3*sizeof(char));
// 	printf("%s\n", str0);
// 	memset(str1, '$', 7);
// 	printf("%s\n", str1);
// 	ft_memset(str1 + 4, 'x', 3*sizeof(char));
// 	printf("%s\n", str1);
// }
