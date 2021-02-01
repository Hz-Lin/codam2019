#include "get_next_line.h"

char	*ft_strjoin(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i])
		i++;
	if (!(str = (char*)malloc(i + 2)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = c;
	str[i + 1] = '\0';
	free(s);
	return (str);
}

int		get_next_line(char **line)
{
	int		count;
	char	*buffer;

	buffer = (char*)malloc(2);
	if (!line || !(*line = (char*)malloc(1)) || !buffer)
		return (-1);
	*line[0] = '\0';
	while ((count = read(0, buffer, 1)) > 0)
	{
		if (buffer[0] == '\n')
			break ;
		*line = ft_strjoin(*line, buffer[0]);
	}
	free(buffer);
	return (count);
}
