/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/05 15:47:42 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/05 15:47:44 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 'a' + 'A');
	}
	return (c);
}

int	main(void)
{
	char ch;

	ch = 'g';
	printf("%c in uppercase is represented as  %c", ch, toupper(ch));
	return (0);
}
