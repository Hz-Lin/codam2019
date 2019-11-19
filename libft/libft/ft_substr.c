/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:26:36 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 13:26:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (start <= ft_strlen(s))
	{
		while (i < len && s[start + i])
		{
			res[i] = s[start + i];
			i++;
		}
	}
	res[i] = '\0';
	return (res);
}
