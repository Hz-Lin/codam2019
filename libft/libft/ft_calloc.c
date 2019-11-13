/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 10:53:28 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 10:53:30 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*res;
	size_t			i;
	unsigned char	*temp;

	i = 0;
	res = malloc(size * count);
	if (res == NULL)
	{
		return (NULL);
	}
	temp = (unsigned char*)res;
	while (i < (count * size))
	{
		temp[i] = 0;
		i++;
	}
	return (res);
}
