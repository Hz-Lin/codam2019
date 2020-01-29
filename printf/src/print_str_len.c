/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_str_len.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 14:12:07 by hlin          #+#    #+#                 */
/*   Updated: 2020/01/29 14:12:10 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int		ft_putchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int		ft_putstrprec(char *str, int len)
{
	int	count;

	count = 0;
	while (str[count] && count < len)
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

int		cal_width(int width, int minus, int zero)
{
	int		count;

	count = 0;
	while (width > minus)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width--;
		count++;
	}
	return (count);
}

char	*ft_str_tolower(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}
