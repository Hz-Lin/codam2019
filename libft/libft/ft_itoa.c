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

int		int_len(int n)
{
	int		nbr;
	int		len;

	nbr = n;
	len = 1;
	while (nbr / 10 != 0)
	{
		nbr = nbr / 10;
		len++;
	}
	if (n < 0)
	{
		len++;
	}
	return (len);
}

void	pos_itoa(char *str, int n, int neg, int len)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = n;
	while ((i + neg) < len)
	{
		str[len - i - 1] = (nbr % 10) + '0';
		i++;
		nbr = nbr / 10;
	}
	str[len] = '\0';
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		nbr;
	char	*res;

	len = int_len(n);
	neg = 0;
	nbr = n;
	res = (char*)malloc((sizeof(*res)) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (n < 0)
	{
		neg = 1;
		res[0] = '-';
		if (n == -2147483647)
		{
			neg = 2;
			res[1] = '2';
			nbr = -147483647;
		}
		nbr = -1 * n;
	}
	pos_itoa(res, nbr, neg, len);
	return (res);
}
