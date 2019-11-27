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

int			ft_atoi(const char *str)
{
	long long	res;
	int			neg;

	res = 0;
	neg = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		if ((res * 10 + (*str - '0')) < res)
			return (((-1 * neg) - 1) / 2);
		res = res * 10 + (*str - '0');
		str++;
	}
	return ((int)(res * neg));
}

// int		main(void)
// {
// 	char	*str;

// 	str = "     +5980";
// 	printf("%d\n", atoi(str));
// 	printf("%d\n", ft_atoi(str));
// 	return (0);
// }
