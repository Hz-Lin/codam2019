/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/06 13:56:55 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/06 13:56:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*temp;
	unsigned int	i;

	temp = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		temp[i] = 0;
		i++;
	}
}

int		main(void)
{
	char str0[50] = "This is string.h library function";
	char str1[50] = "This is string.h library function";

	bzero(str0, 7);
	printf("%s\n", str0);
	ft_bzero(str0 + 4, 3*sizeof(char));
	printf("%s\n", str0);
	bzero(str1, 7);
	printf("%s\n", str1);
	ft_bzero(str1 + 4, 3*sizeof(char));
	printf("%s\n", str1);
}
