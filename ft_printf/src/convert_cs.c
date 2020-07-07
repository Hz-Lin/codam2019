/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_cs.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/03 16:20:22 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/06 23:02:06 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*strloc(int len)
{
	char	*res;
	int		i;

	i = 0;
	res = (char *)malloc(sizeof(char) * len);
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}

char	*convert_c(t_flags flags, va_list args)
{
	char	*res;

	res = (char *)strloc(2);
	if (res == NULL)
		return (NULL);
	if (flags.type == '%')
		res[0] = flags.type;
	if (flags.type == 'c')
		res[0] = va_arg(args, int);
	res[1] = 0;
	return (res);
}

char	*convert_s(const char *str, t_flags flags)
{
	int		i;
	int		len;
	char	*res;

	len = 0;
	i = 0;
	if (str = NULL)
		return (convert_s("(null)", flags));
	while (str[len])
		len++;
	if (len > flags.max_width && flags.precision == 1)
		len = flags.max_width;
	res = strloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (i < len)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
