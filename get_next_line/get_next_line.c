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

char	*get_line(char *s, char *buffer, int read_bytes)
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
	free_buffer(buffer, read_bytes);
	return (res);
}

int		get_newline(char *buffer, char **line, int read_bytes)
{
	int	i;

	i = 0;
	while (buffer[i] && i < read_bytes)
	{
		if (buffer[i] == '\n')
		{
			*line = get_line(*line, buffer, read_bytes);
			if (line == NULL)
				return (-1);
			renew_buffer(buffer, read_bytes);
			return (1);
		}
		i++;
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_bytes;
	int			res;

	read_bytes = BUFFER_SIZE;
	*line = NULL;
	while (read_bytes > 0)
	{
		res = get_newline(buffer, line, read_bytes);
		if (res != 0)
			return (res);
		*line = get_line(*line, buffer, read_bytes);
		read_bytes = read(fd, buffer, BUFFER_SIZE);
	}
	*line = get_line(*line, buffer, read_bytes);
	return (read_bytes);
}
