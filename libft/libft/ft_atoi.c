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

int	check_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
	{
		return (1);
	}
	else if (c == '\r' || c == '\v' || c == '\f')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	check_negative(char c)
{
	if (c == '-')
	{
		return (-1);
	}
	return (1);
}

int	res_verylong(int neg)
{
	if (neg == 1)
	{
		return (-1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					neg;

	res = 0;
	neg = 1;
	while (check_white_space(*str) == 1)
		str++;
	if (*str == '+' || *str == '-')
	{
		neg = check_negative(*str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	if (res > 9223372036854775807)
		res = res_verylong(neg);
	return (res * neg);
}
