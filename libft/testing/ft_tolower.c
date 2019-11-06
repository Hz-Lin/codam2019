/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tolower.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:55:14 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 15:55:16 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c - 'A' + 'a');
	}
	return (c);
}

int	main(void)
{
	char ch;

	ch = 'G';
	printf("%c in lowercase is represented as  %c", ch, ft_tolower(ch));
	return (0);
}
