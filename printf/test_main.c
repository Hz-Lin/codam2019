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
	printf("or: %c\n", 'x');
	printf("String: %-30.30s\n", "This is a test!");
	printf("String: %d\n", 1024);
	printf("String: %i\n", 1024);
	printf("String: %00.5%\n");
	return (0);
}
