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
	unsigned int num = 0x25a58;
	char 			*ptr;
	unsigned int	n;

	ptr = "This is a test";
	n = 56;
	printf("%4c\n", 'x');
	printf("%-2.3s\n", "123456789");
	printf("%-10.7d\n", 123456);
	printf("%10.7d\n", 123456);
	printf("%-20p\n", ptr);
	printf("%-10.7u\n", n);
	printf("%-10.5x\n", num);
	printf("%-10.7X\n", num);
	// printf("%%d shows: %d, %%u shows: %u\n", num, num);
	return (0);
}
