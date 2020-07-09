/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsers_utilites.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 23:39:06 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/10 00:40:42 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

int			is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u')
		return (1);
	else if (c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int			is_flag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	else if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

long long	ft_atol(const char *str, int *size)
{
	long long			neg;
	unsigned long long	res;
	int					i;

	i = 0;
	res = 0;
	neg = 1;
	while (str[i] && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	*size += (i - 1);
	return (res * neg);
}
