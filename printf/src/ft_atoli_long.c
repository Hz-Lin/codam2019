/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoli_long.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 17:13:29 by hlin           #+#    #+#                */
/*   Updated: 2020/03/24 15:05:57 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_atoi_long(char *str, int *size)
{
	long long			negative;
	unsigned long long	res;
	int					i;

	i = 0;
	negative = 1;
	res = 0;
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == ' '))
		i++;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			negative = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	size += (i - 1);
	return (res * negative);
}
