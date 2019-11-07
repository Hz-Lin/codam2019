/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 12:01:53 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 12:01:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		str_len;
	int		i;
	char	*dup;

	str_len = 0;
	i = 0;
	while (str[str_len] != '\0')
	{
		str_len++;
	}
	dup = (char*)malloc(sizeof(*dup) * (str_len + 1));
	while (i < str_len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
