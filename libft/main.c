/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 11:27:29 by hlin          #+#    #+#                 */
/*   Updated: 2019/10/29 11:27:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    char str[50] = "This is string.h library function";

    printf("result of ft_strlen: %lu\n", ft_strlen(str));
    printf("result of strlen: %lu\n", strlen(str));
    
    // ft_memset(4, '$', 7);
    // printf("%s", str);
    // ft_memset(str + 4, 'x', 3*sizeof(char));
    // printf("%s", str);


}
