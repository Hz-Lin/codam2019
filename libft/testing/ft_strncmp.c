/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 17:06:06 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/04 17:06:09 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	ptr_s1 = (unsigned char*)s1;
	ptr_s2 = (unsigned char*)s2;
	while (*ptr_s1 && *ptr_s1 == *ptr_s2 && n > 0)
	{
		ptr_s1++;
		ptr_s2++;
		n--;
	}
	return (*ptr_s1 - *ptr_s2);
}

int	main(void)
{
	const char	*str1;
	const char	*str2;

	str1 = "function";
	str2 = "functioN";
	printf("%d\n", strncmp(str1, str2, 5));
	printf("%d\n", ft_strncmp(str1, str2, 5));
	return (0);
}
