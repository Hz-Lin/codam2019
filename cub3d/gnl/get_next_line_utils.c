/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:54:45 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/01 16:27:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		cal_strlen(char *s)
{
	int len;

	len = 0;
	if (s == NULL)
		return (0);
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

void	free_buffer(char *buffer, int read_bytes)
{
	int	i;

	i = 0;
	while (i < read_bytes && buffer[i] != '\n')
	{
		buffer[i] = 0;
		i++;
	}
}

char	*join_strbuff(char *s, char *buffer, int read_bytes)
{
	int		i;
	char	*res;

	i = 0;
	res = (char*)malloc((sizeof(*res)) * (cal_strlen(s) + read_bytes + 1));
	if (!res)
		return (NULL);
	if (s)
	{
		while (s[i])
		{
			res[i] = s[i];
			i++;
		}
	}
	while (i < (cal_strlen(s) + read_bytes))
	{
		res[i] = *buffer;
		i++;
		buffer++;
	}
	res[i] = '\0';
	return (res);
}

void	renew_buffer(char *buffer, int read_bytes)
{
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (start < read_bytes && buffer[start] != '\n')
		start++;
	if (buffer[start] == '\n')
		start++;
	while (i < (read_bytes - start))
	{
		buffer[i] = buffer[start + i];
		i++;
	}
	while (i < read_bytes)
	{
		buffer[i] = 0;
		i++;
	}
}
