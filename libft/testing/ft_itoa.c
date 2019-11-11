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
#include <stdio.h>

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

void	fill_str(char *str, int n, int neg, int len)
{
	int		i;
	int		nbr;

	i = len;
	nbr = n;
	while (len > 0)
	{
		str[len + neg - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		nbr;
	char	*res;
	int		i;

	len = int_len(n);
	neg = 0;
	nbr = n;
	i = 0;
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
	while ((i + neg) < len)
	{
		// printf("%d\n", (i + neg));
		res[i + neg] = (nbr / 10) + '0';
		printf("%d\n", (nbr % 10));
		i++;
		nbr = nbr / 10;
	}
	res[len] = '\0';
	return (res);
}

int		main(void)
{
	int		x;

	x = -2147483647;
	printf("%s\n", ft_itoa(x));
	return (0);
}
