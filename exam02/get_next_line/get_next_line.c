#include "get_next_line.h"

int		ft_strlen(char *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *remain, char *buffer)
{
	unsigned int	size;
	int				i;
	int				j;
	char			*array;

	if (!remain && !buffer)
		return (NULL);
	size = ft_strlen(remain) + ft_strlen(buffer);
	if (!(array = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (remain)
	{
		while (remain[i])
		{
			array[j] = remain[i];
			i++;
			j++;
		}
		i = 0;
	}
	while (buffer[i])
	{
		array[j] = buffer[i];
		i++;
		j++;
	}
	array[size] = '\0';
	free((void*)remain);
	return (array);
}

char	*push_line(char *remain)
{
	int		i;
	char	*array;

	i = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (!(array = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remain[i] && remain[i] != '\n')
	{
		array[i] = remain[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*cut_line(char *remain)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	while (remain[i] && remain[i] != '\n')
		i++;
	if (!remain[i])
	{
		free(remain);
		return (NULL);
	}
	if (!(array = (char*)malloc(sizeof(char) * (ft_strlen(remain) - i + 1))))
		return (NULL);
	i++;
	while (remain[i])
	{
		array[j] = remain[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free(remain);
	return (array);
}

int		get_next_line(char **line)
{
	int				count;
	static char		*remain;
	char			buffer[BUFFER_SIZE + 1];

	count = 1;
	if (!line)
		return (-1);
	while (buffer[0] != '\n' && count != 0)
	{
		if ((count = read(0, buffer, BUFFER_SIZE)) == -1)
			return (-1);
		buffer[count] = '\0';
		remain = ft_strjoin(remain, buffer);
	}
	*line = push_line(remain);
	remain = cut_line(remain);
	return ((count == 0) ? 0 : 1);
}
