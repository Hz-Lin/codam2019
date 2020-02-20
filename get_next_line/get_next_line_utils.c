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

int		parse(int result, char **line, char **s)
{
	if (result == 0 || result == 1)
	{
		*line = *s;
	}
	else
	{
		free(*s);
	}
	return (result);
}

int		free_buffer(char *buffer, int read_bytes, int full)
{
	int	i;

	i = 0;
	if (full == 0)
	{
		while (i < read_bytes && buffer[i] = '\n')
		{
			buffer[i] = 0;
			i++;
		}
	}
	else
	{
		while (i < read_bytes)
		{
			buffer[i] = 0;
			i++;
		}
	}
	
}

char	*join_strbuff(char *s, char *buffer, int read_bytes)
{
	int		i;
	char	*res;

	res = (char*)malloc((sizeof(*res)) * (ft_strlen(s) + read_bytes + 1));
	if (res == NULL)
	{
		return (NULL);
	}
	i = 0;
	if (s)
	{
		while (s[i])
		{
			res[i] = s[i];
			i++;
		}
	}
	while (i < ft_strlen(s) + read_bytes)
	{
		res[i] = *buffer;
		i++;
		buffer++;
	}
	res[i] = '\0';
	return (res);
}

void	move_buffer(char *buffer, int read_bytes)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (start < read_bytes && buffer[start] != '\n')
		start++;
	if (buffer[start] == '\n')
		i++;
	while (i < (read_bytes - start))
	{
		buffer[i] = buffer[start + 1];
		i++;
	}
	while (i < read_bytes)
	{
		buffer[i] = 0;
		i++;
	}
}
