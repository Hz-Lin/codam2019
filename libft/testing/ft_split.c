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

void	*free_str(char **str)
{
	int		i;

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
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c && (i > 0 && s[i - 1] != c))
		{
			count++;
		}
		i++;
	}
	return (count);
}

char	*copy_word(const char *str, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	res = (char*)malloc(sizeof(*res) * (n + 1));
	if (res == NULL)
		return (NULL);
	while (i < n)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// size_t	word_len(char const *s, char c, size_t start)
// {
// 	size_t	len;

// 	len = 0;
// 	while (s[start] != '\0' && s[start] != c)
// 	{
// 		len++;
// 		start++;
// 	}
// 	return (len);
// }

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	words;
	char	**res;

	i = 0;
	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	res = (char**)malloc(sizeof(char*) * (words + 1));
	if (res == NULL)
		return (NULL);
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		printf("%zu\n", i);
		if (s[i] == c)
			continue ;
		j = 0;
		while (s[i + j] && s[i + j] != c)
		{
			j++;
		}
		res[words] = copy_word(&s[i], j);
		words++;
		if (res == NULL)
			return (free_str(res));
		i = i + j - 1;
		i++;
	}
	return (res);
}

/* war machine test */
void	ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

int		main(void)
{
	// char const *s;
	// char		c;
	// char		**res;
	// size_t		i;

	// i = 0;
	// s = "      split       this for   me  !       ";
	// c = ' ';
	// res = ft_split(s, c);
	// while (i < count_words(s, c))
	// {
	// 	printf("%s\n", res[i]);
	// 	i++;
	// }

	// char	**tabstr;
	// int		i;

	// i = 0;
	// if (!(tabstr = ft_split("  t    y  ", ' ')))
	// 	ft_print_result("NULL");
	// else
	// {
	// 	while (tabstr[i] != '\0')
	// 	{
	// 		ft_print_result(tabstr[i]);
	// 		write(1, "\n", 1);
	// 		i++;
	// 	}
	// }

	char const *s;
	char		c;
	char		*res;
	size_t		i;

	i = 0;
	s = "      split       this for   me  !       ";
	c = ' ';
	printf("%zu\n", count_words(s, c));
	res = copy_word(&s[6], 5);
	printf("%s\n", res);
	// while (i < count_words(s, c))
	// {
	// 	printf("%s\n", res[i]);
	// 	i++;
	// }
	return (0);
}
