/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:54:45 by hlin          #+#    #+#                 */
/*   Updated: 2020/02/07 11:54:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s != c)
	{
		if (*s == '\0')
		{
			return (NULL);
		}
		s++;
	}
	return ((char*)s);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		i;
	char	*dup;

	len = ft_strlen(s);
	i = 0;
	dup = (char*)malloc(sizeof(*dup) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, int start, int len)
{
	int		i;
	int		s_len;
	char	*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len && s_len > start)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;

	if (!s1 || !s2)
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
