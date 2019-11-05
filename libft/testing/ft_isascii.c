/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isascii.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 14:50:47 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 14:50:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}

int	main(void)
{
	int ch;

	for (ch = 0x7c; ch <= 0x82; ch++)
	{
		printf("%#04x    ", ch);
		if (isascii(ch))
			printf("The character is %c\n", ch);
		else
			printf("Cannot be represented by an ASCII character\n");
	}
	for (ch = 0x7c; ch <= 0x82; ch++)
	{
		printf("%#04x    ", ch);
		if (ft_isascii(ch))
			printf("The character is %c\n", ch);
		else
			printf("Cannot be represented by an ASCII character\n");
	}
	return 0;
}
