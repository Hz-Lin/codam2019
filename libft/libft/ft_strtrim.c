/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:47:55 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 15:47:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check_c(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		cal_start(char const *s1, char const *set)
{
	int		start;

	start = 0;
	while (check_c(set, s1[start]) == 1)
	{
		start++;
	}
	return (start);
}

int		cal_end(char const *s1, char const *set)
{
	int		end;

	end = ft_strlen(s1) - 1;
	while (check_c(set, s1[end]) == 1)
	{
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		end;
	int		start;

	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0' || set[0] == '\0')
		return ((char*)s1);
	start = cal_start(s1, set);
	end = cal_end(s1, set);
	if ((end - start) < 0)
		return ("");
	res = (char*)malloc(sizeof(*res) * (end - start + 2));
	if (res == NULL)
		return (NULL);
	res = ft_substr(s1, start, (end - start + 1));
	return (res);
}
