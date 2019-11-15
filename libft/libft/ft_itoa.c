/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/08 16:13:10 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/08 16:13:12 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_len(long nbr)
{
	int			len;

	len = 0;
	if (nbr < 0)
	{
		len++;
		nbr = -1 * nbr;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	if (len == 0)
		len++;
	return (len);
}

int		if_negtive(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	long	nbr;
	long	len;
	char	*res;

	nbr = (long)n;
	len = int_len(nbr);
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	res[len] = '\0';
	len--;
	if (nbr < 0)
		nbr = -1 * nbr;
	while (len >= 0)
	{
		res[len] = (nbr % 10) + '0';
		len--;
		nbr = nbr / 10;
	}
	if (if_negtive(n) == 1)
		res[0] = '-';
	return (res);
}
