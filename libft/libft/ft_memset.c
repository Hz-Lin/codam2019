/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 11:29:52 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 11:29:54 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char*)b;
	i = 0;
	if (len == 0)
	{
		return (b);
	}
	while (i < len)
	{
		temp[i] = c;
		i++;
	}
	return (b);
}
