/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 12:55:36 by hlin          #+#    #+#                 */
/*   Updated: 2019/10/29 12:55:39 by hlin          ########   odam.nl         */
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

int		main(void)
{
	char	str[50] = "This is string.h library function";

	printf("result of ft_strlen: %lu\n", ft_strlen(str));
	printf("result of strlen: %lu\n", strlen(str));
}
