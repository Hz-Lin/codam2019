/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:56:55 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 13:56:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	unsigned int	i;

	temp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}
