/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 11:27:31 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/08 11:27:33 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*str_trim(char const *s, char c)
{
	char	*res;
	int		len;
	int		start;

	if (!s)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (s[len - 1] == c)
	{
		len--;
	}
	while (s[start] == c)
	{
		start++;
		len--;
	}
	if (len < 0)
		len = 0;
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	res = ft_substr(s, start, len);
	return (res);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && (i > 0 && s[i - 1] != c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

size_t	word_len(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		len++;
		start++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	i;
	char	*src;
	char	**res;

	j = 0;
	i = 0;
	src = str_trim(s, c);
	if (src == NULL)
		return (NULL);
	res = (char**)malloc((sizeof(*res) * (count_words(src, c) + 1)));
	if (res == NULL)
		return (NULL);
	res[j] = ft_substr(src, 0, word_len(src, c, 0));
	while (i < (ft_strlen(src) - 1))
	{
		if (src[i] == c && src[i + 1] != c)
		{
			j++;
			res[j] = ft_substr(src, (i + 1), word_len(src, c, (i + 1)));
		}
		i++;
	}
	return (res);
}

// int		main(void)
// {
// 	char const *s;
// 	char		c;
// 	char		**res;
// 	size_t		i;

// 	s = "      split       this for   me  !       ";
// 	c = ' ';
// 	i = 0;
// 	res = ft_split(s, c);
// 	while (i < count_words(s, c))
// 	{
// 		printf("%s\n", res[i]);
// 		i++;
// 	}
// 	return (0);
// }
