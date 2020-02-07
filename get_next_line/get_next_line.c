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

char	*ft_begin_nxtline(char *s)
{
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (0);
	}
	res = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!res)
		return (0);
	i++;
	while (s[i])
	{
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	free(s);
	return (res);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*save;
	int			rtn;

	rtn = 1;
	if (!line || BUFFER_SIZE <= 0)
		return (-1);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	while (!ft_is_eol(save) && rtn != 0)
	{
		rtn = read(fd, buf, BUFFER_SIZE);
		if (rtn == -1)
			return (-1);
		buf[rtn] = '\0';
		save = ft_strjoin(save, buf);
	}
	free(buf);
	*line = ft_setline(save);
	save = ft_begin_nxtline(save);
	if (rtn == 0)
		return (0);
	return (1);
}
