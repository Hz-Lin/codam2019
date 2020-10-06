/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_two.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/02 23:54:09 by hlin          #+#    #+#                 */
/*   Updated: 2020/10/04 16:03:25 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int			ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (str1[i] - str2[i]);
		else
			i++;
	}
	return (str1[i] - str2[i]);
}

char		*ft_strdup(const char *s1)
{
	int		len;
	int		i;
	char	*s2;

	len = 0;
	i = 0;
	while (s1[len])
		len++;
	s2 = malloc(sizeof(*s1) * (len + 1));
	if (!s2)
		return (0);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

intmax_t	ft_atoi(char *line, int *i)
{
	int			sign;
	intmax_t	n;

	sign = 1;
	n = 0;
	skip_wp(line, i);
	if (line[*i] == '-' || line[*i] == '+')
	{
		if (line[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (is_num(line, *i))
	{
		if (n >= 922337203685477580)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		n = n * 10 + (line[*i] - '0');
		(*i)++;
	}
	return (sign * n);
}
