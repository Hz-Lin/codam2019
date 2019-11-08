/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 10:48:35 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 10:48:41 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	sign;
	int	neg;

	res = 0;
	i = 0;
	sign = 1;
	neg = 0;
	if (str[0] == '-')
	{
		sign = -1;
		neg = 1;
	}
	while (str[i + neg] != '\0' && str[i + neg] <= '9' && str[i + neg] >= '0')
	{
		res = res * 10 + (str[i + neg] - '0');
		i++;
	}
	return (res * sign);
}

// int	main(void)
// {
// 	char	*str;

// 	str = "-2147483649";
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }
