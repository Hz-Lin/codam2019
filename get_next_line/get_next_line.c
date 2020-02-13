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

static int	read_buffer(int fd, char **remain)
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
		*remain = ft_strjoin(*remain, buf);
		if (*remain == NULL)
			return (-1);
		if (ft_strchr(*remain, '\n'))
			break ;
	}
	if (read_return > 0)
		return (1);
	else
		return (0);
}

static int	find_end_index(char *remain)
{
	int	end;

	end = 0;
	while (remain[end] != '\n' && remain[end] != '\0')
		end++;
	return (end);
}

static int	extract_line(char **remain, char **line)
{
	int		end;
	int		res;
	char	*temp;

	end = find_end_index(*remain);
	*line = ft_substr(*remain, 0, end);
	temp = *remain;
	*remain = ft_substr(temp, end + 1, ft_strlen(temp));
	if (temp[end] == '\0')
		res = 0;
	else
		res = 1;
	free(temp);
	return (res);
}

int			get_next_line(int fd, char **line)
{
	static char	*rest;
	int			ret;

	if (fd < 0 || line == NULL || read(fd, 0, 0) == -1)
		return (-1);
	if (rest == NULL)
		rest = ft_strdup("");
	if (rest == NULL)
		return (-1);
	ret = read_buffer(fd, &rest);
	if (ret < 0)
	{
		free(rest);
		rest = NULL;
	}
	else
	{
		ret = extract_line(&rest, line);
		if (ret == 0)
		{
			free(rest);
			rest = NULL;
		}
	}
	return (ret);
}
