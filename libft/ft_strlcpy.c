/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/29 13:55:52 by hlin          #+#    #+#                 */
/*   Updated: 2019/10/29 13:55:55 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    int len;
    int i;

    len = 0;
    i = 0;
    while(src[len] != 0)
    {
        len++;
    }
    while(src[i] != '\0' && i < (len - 1))
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    return (len);
}
