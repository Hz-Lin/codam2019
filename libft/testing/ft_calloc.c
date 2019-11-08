/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 10:53:28 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 10:53:30 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	i;

	i = 0;
	if (count == 0 || size == 0)
	{
		return (NULL);
	}
	res = malloc(size * count);
	if (res == NULL)
	{
		return (NULL);
	}
	while (i <= count)
	{
		((char*)res)[i] = 0;
		i++;
	}
	return (res);
}

// int		main(void)
// {
// 	int	i;
// 	int	n;
// 	int	*a;

// 	printf("Number of elements to be entered:");
// 	scanf("%d", &n);
// 	a = (int*)calloc(n, sizeof(int));
// 	printf("Enter %d numbers:\n", n);
// 	for( i=0 ; i < n ; i++ )
// 	{
// 		scanf("%d",&a[i]);
// 	}

// 	printf("The numbers entered are: ");
// 	for( i=0 ; i < n ; i++)
// 	{
// 		printf("%d ", a[i]);
// 	}
// 	free(a);
// 	return (0);
// }
