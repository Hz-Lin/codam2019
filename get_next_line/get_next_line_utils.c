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

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	ptr_dst = (unsigned char*)dst;
	ptr_src = (unsigned char*)src;
	i = 0;
	if (ptr_src == NULL && ptr_src == ptr_dst)
		return (dst);
	if (ptr_src < ptr_dst)
		while (i < len)
		{
			i++;
			ptr_dst[len - i] = ptr_src[len - i];
		}
	else
		while (len > 0)
		{
			*(ptr_dst) = *(ptr_src);
			ptr_dst++;
			ptr_src++;
			len--;
		}
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
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

int		ft_is_eol(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	ft_setline(char *s)
{
	int		i;
	char	*res;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (0);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\n';
	return (res);
}
