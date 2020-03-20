/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   string_functions.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/13 11:00:35 by hlin           #+#    #+#                */
/*   Updated: 2020/03/13 11:00:38 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */



#include "../includes/ft_printf.h"

char	*ft_malloc_str(int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char*)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
