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

void	*free_str(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*copy_word(const char *str, char c)
{
	char	*word;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	len = 0;
	while (str[i] == c)
		i++;
	while (str[i + len] != c && str[i + len] != '\0')
		len++;
	word = (char*)malloc(sizeof(*word) * (len + 1));
	if (word == NULL)
		return (NULL);
	while (j < len)
	{
		word[j] = str[i + j];
		j++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**res;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	res = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if ((i == 0 && s[0] != c) || (i > 0 && s[i] != c && s[i - 1] == c))
		{
			res[j] = copy_word(&s[i], c);
			if (res[j] == NULL)
				return (free_str(res));
			j++;
		}
		i++;
	}
	res[count_words(s, c)] = NULL;
	return (res);
}
