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

#include <string.h>
#include <stdio.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (n - 1) && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
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
