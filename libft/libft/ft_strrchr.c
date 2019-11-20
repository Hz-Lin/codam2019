/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 17:55:37 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/01 17:55:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	char	*res;
	char	*str;
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	str = (char*)s;
	while (i <= ft_strlen(s))
	{
		if (str[i] == (char)c)
		{
			res = &str[i];
			count++;
		}
		i++;
	}
	if (count != 0)
		return (res);
	return (NULL);
}
