/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 15:18:46 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/09 15:18:48 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

int		main(void)
{
	char	c;
	char	*s;
	int		di;

	c = 'x';
	s = "This is a test!";
	di = 1024;
	printf("or: %c", c);
	printf("String: %s", s);
	printf("String: %d", di);
	printf("String: %i", di);
	return (0);
}
