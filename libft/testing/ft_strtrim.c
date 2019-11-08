/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:47:55 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 15:47:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

// size_t	ft_strlen(const char *s)
// {
// 	int len;

// 	len = 0;
// 	while (s[len] != '\0')
// 	{
// 		len++;
// 	}
// 	return (len);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	i;
// 	char	*res;

// 	i = 0;
// 	if (len == 0)
// 	{
// 		return (NULL);
// 	}
// 	res = (char*)malloc(sizeof(*res) * (len + 1));
// 	if (res == NULL)
// 	{
// 		return (NULL);
// 	}
// 	while (i < len)
// 	{
// 		res[i] = s[start + i];
// 		i++;
// 	}
// 	return (res);
// }

int		check_c(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		len;
	int		start;

	if (!s1 || !set || s1[0] == '\0' || set[0] == '\0')
		return (NULL);
	start = 0;
	len = ft_strlen(s1);
	while (check_c(set, s1[len - 1]) == 1)
	{
		len--;
	}
	while (check_c(set, s1[start]) == 1)
	{
		start++;
		len--;
	}
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	res = ft_substr(s1, start, len);
	return (res);
}

// int		main(void)
// {
// 	char const	str[] = "ababavvvabxxxbbaab";
// 	char const	set[] = "ab";

// 	printf("%s\n", ft_strtrim(str, set));
// 	return (0);
// }
