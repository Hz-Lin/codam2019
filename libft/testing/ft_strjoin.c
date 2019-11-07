/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 14:10:54 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 14:10:57 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	char		*res;

	if (ft_strlen(s1) == 0 || ft_strlen(s2) == 0)
	{
		return (NULL);
	}
	res = (char*)malloc((sizeof(*res)) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < ft_strlen(s1) + ft_strlen(s2))
	{
		if (i < ft_strlen(s1))
			res[i] = s1[i];
		else
			res[i] = s2[i - ft_strlen(s1)];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int		main(void)
{
	char const	s1[] = "Bilbo Bagins is a theft!";
	char const	s2[] = "What shoud we do?";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
}
