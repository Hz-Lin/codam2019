/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser_utilities.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: evelina <evelina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/02 00:08:33 by evelina       #+#    #+#                 */
/*   Updated: 2020/06/24 14:03:34 by evelina       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int			putstr(const char *str, t_flags flags)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	if (str[i] == 0 && flags.type == 'c')
	{
		write(1, &str[i], 1);
		count++;
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		count++;
	}
	return (count);
}

int			is_type(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' | c == 'u')
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

int			match(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
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
