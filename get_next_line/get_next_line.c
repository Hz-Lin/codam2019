/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:54:56 by hlin          #+#    #+#                 */
/*   Updated: 2020/02/07 11:55:00 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	ft_realloc(char *s, char *buffer, int read_bytes)
{
	char	*res;

	if (read_bytes == -1)
	{
		free(s);
		return (NULL);
	}
	if (read_bytes > ft_strlen(buffer))
		read_bytes = ft_strlen(buffer);
	res = join_strbuff(s, buffer, read_bytes);
	free(s);
	free_buffer(buffer, read_bytes, 0);
	return (res);
}

int		is_newline(char *buffer, char **line, int read_bytes)
{
	int	i;

	i = 0;
	while (buffer[i] && i < read_bytes)
	{
		if (buffer[i] == '\n')
		{
			*line = ft_realloc(*line, buffer, read_bytes);
			if (line == NULL)
				return (-1);
			move_buffer(buffer, read_bytes);
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer[BUFFER_SIZE + 1];
	int			read_bytes;
	int			ret;

	read_bytes = BUFFER_SIZE;
	*line = NULL;
	while (read_bytes > 0)
	{
		ret = is_newline(buffer, line, read_bytes);
		if (ret != 0)
			return (ret);
		*line = ft_realloc(*line, buffer, read_bytes);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	*line = ft_realloc(*line, buffer, read_bytes);
	return (read_bytes);
}
