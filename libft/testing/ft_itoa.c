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
	char	*res;

	len = int_len(n);
	neg = 0;
	nbr = n;
	res = (char*)malloc((sizeof(*res)) * (len + 1));
	if (res == NULL)
		return (NULL);
	if (nbr == -2147483647)
		return (ft_strcpy(res, "-2147483648"));
	if (n < 0)
	{
		neg = 1;
		res[0] = '-';
		nbr = -1 * n;
	}
	pos_itoa(res, nbr, neg, len);
	return (res);
}

int		main(void)
{
	int		x;

	x = -2147483647;
	printf("%s\n", itoa(x));
	printf("%s\n", ft_itoa(x));
	return (0);
}
