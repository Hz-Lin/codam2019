/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 17:41:44 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 17:41:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	if (n == 0)
	{
		return (0);
	}
	while (n > 0)
	{
		if (*ptr1 != *ptr2)
		{
			return (*ptr1 - *ptr2);
		}
		n--;
		ptr1++;
		ptr2++;
	}
	return (0);
}

// int		main(void)
// {
// 	char	str1[15];
// 	char	str2[15];
// 	int		ret;

// 	memcpy(str1, "", 6);
// 	memcpy(str2, "", 6);
// 	ret = memcmp(str1, str2, 5);
// 	if (ret > 0)
// 	{
// 		printf("str2 is less than str1\n");
// 	}
// 	else if(ret < 0)
// 	{
// 		printf("str1 is less than str2\n");
// 	}
// 	else
// 	{
// 		printf("str1 is equal to str2\n");
// 	}
// 	ret = ft_memcmp(str1, str2, 5);
// 	if (ret > 0)
// 	{
// 		printf("str2 is less than str1\n");
// 	}
// 	else if (ret < 0)
// 	{
// 		printf("str1 is less than str2\n");
// 	}
// 	else
// 	{
// 		printf("str1 is equal to str2\n");
// 	}
// 	return (0);
// }
