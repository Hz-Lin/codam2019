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

static int	read_buffer(int fd, char **file)
{
	static char	buf[BUFFER_SIZE + 1];
	int			read_return;

	read_return = 1;
	while (read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return < 0)
			return (-1);
		buf[read_return] = '\0';
		*file = ft_strjoin(*file, buf);
		if (*file == NULL)
			return (-1);
		if (ft_strchr(*file, '\n'))
			break ;
	}
	if (read_return > 0)
		return (1);
	else
		return (0);
}

static int	find_end_index(char *file)
{
	int	end;

	end = 0;
	while (file[end] != '\n' && file[end] != '\0')
		end++;
	return (end);
}

static int	extract_line(char **file, char **line)
{
	int		end;
	int		res;
	char	*temp;

	end = find_end_index(*file);
	*line = ft_substr(*file, 0, end);
	temp = *file;
	*file = ft_substr(temp, end + 1, ft_strlen(temp));
	if (temp[end] == '\0')
		res = 0;
	else
		res = 1;
	free(temp);
	return (res);
}

int			get_next_line(int fd, char **line)
{
	static char	*buffer[BUFFER_SIZE + 1];
	int			read_res;
	int			ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0) == -1)
		return (-1);
	if (file == NULL)
		file = ft_strdup("");
	if (file == NULL)
		return (-1);
	ret = read_buffer(fd, &file);
	if (ret < 0)
	{
		free(file);
		file = NULL;
	}
	else
	{
		ret = extract_line(&file, line);
		if (ret == 0)
		{
			free(file);
			file = NULL;
		}
	}
	return (ret);
}
