/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/19 00:18:24 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/06 23:45:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		main(void)
{
	// int	a;

	// a = 42;
	// printf("print p\n");
	// printf("%16p\n", &a);
	// ft_printf("%16p\n", &a);

	// printf("print c\n");
	// printf("%7c\n", 'x');
	// ft_printf("%7c\n", 'x');

	// printf("print s\n");
	// printf("%20s\n", "this is a test");
	// ft_printf("%20s\n", "this is a test");

	printf("print d and i\n");
	printf("%7d\n", 88);
	ft_printf("%7d\n", 88);
	printf("%7i\n", 77);
	ft_printf("%7i\n", 77);

	// printf("print x and X\n");
	// printf("%7x\n", 90);
	// ft_printf("%7x\n", 90);
	// printf("%7X\n", 90);
	// ft_printf("%7X\n", 90);

	return (0);
}
