/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:49:37 by hlin          #+#    #+#                 */
/*   Updated: 2020/07/10 00:40:47 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

#define YES "test %p %x %s %s %p %c %X %x %% --  -- %d - %u\n", "f", 0xFFFF,  NULL, "hoi", "abc", 'C', 0, 9, -42, 5
int     main(void)
{
    ft_printf(YES);
    printf(YES);
    ft_printf("%%: %p %x %x %c, %s, %p, %d, %i, %u, %x, %X\n", "h", 23000, 17, '\0', NULL, NULL, 42, -42, 100000, 0xFFFF, 0xFFFF);
    printf("%%: %p %x %x %c, %s, %p, %d, %i, %u, %x, %X\n", "h", 23000, 17, '\0', NULL, NULL, 42, -42, 100000, 0xFFFF, 0xFFFF);
    ft_printf("%s%ihello%-17.14u%i%08d%s%17ssomestuff%s%i%.24u%u%u%.2s%i","abc",-8875, 100,-2147483648,3047,"wassup","nope","",0,2147483647,0u,878023,"notall",2147483647);
    printf("\n");
    printf("%s%ihello%-17.14u%i%08d%s%17ssomestuff%s%i%.24u%u%u%.2s%i","abc",-8875, 100,-2147483648,3047,"wassup","nope","",0,2147483647,0u,878023,"notall",2147483647);
    ft_printf("ik: test %p %x %s %s %p %c %X %x %% --  -- %d %d - %u\n", "f", 17,  NULL, "hoi", "abc", 'C', 0, 9, -42, 10000005, 5);
    printf("\n");
    printf("ik: test %p %x %s %s %p %c %X %x %% --  -- %d %d - %u\n", "f", 17,  NULL, "hoi", "abc", 'C', 0, 9, -42, 10000005, 5);
    ft_printf("%.5p", 0);
    printf("\n");
    printf("%.5p", 0);
    printf("\n");
    ft_printf("%.p", NULL);
    printf("\n");
    printf("%.p", NULL);
    printf("\n");
    ft_printf("%.*s", -3, "hoi");
    printf("\n");
    printf("%.*s", -3, "hoi");
    printf("\n");
    printf("%s-0\n", "hola pirinola");
    ft_printf("%s-0\n", "hola pirinola");

    printf("%x %x %x %x %x %x %x %x %x %x %X %X %X %X %X %X %X %X %X %X\n", 123123123,324435345,36352432345,52434523425,5231234122654,1234213413254,213432412,12,243532453246,123441324312,342121341234123412,123413243241,13242134,12543634563,123412341234,678967896,8679,75874674567,56878678567,34534534534);
    ft_printf("%x %x %x %x %x %x %x %x %x %x %X %X %X %X %X %X %X %X %X %X\n", 123123123,324435345,36352432345,52434523425,5231234122654,1234213413254,213432412,12,243532453246,123441324312,342121341234123412,123413243241,13242134,12543634563,123412341234,678967896,8679,75874674567,56878678567,34534534534);
    
    printf("------------\n");
    ft_printf("ft: %.4p %x %X %c %.s %p %d %i %x %X %p", "hi", 2300, 0, 'v', "hoi", NULL, 23, 45, 17, 40908, NULL);
    printf("\n");
    printf("rl: %.4p %x %X %c %.s %p %d %i %x %X %p", "hi", 2300, 0, 'v', "hoi", NULL, 23, 45, 17, 40908, NULL);
    printf("\n");
    printf("------------\n");

    ft_printf("|ft: st120 %*s|\n", 100, "hello");
    printf("|rl: st120 %*s|\n------------\n", 100, "hello");
    ft_printf("|ft: neg9 %*.*s|\n", 158, 155, "coucou");
    printf("|rl: neg9 %*.*s|\n------------\n", 158, 155, "coucou");
    ft_printf("|ft: neg10 %*.*s|\n", -155, 15, "coucou");
    printf("|rl: neg10 %*.*s|\n------------\n", -155, 15, "coucou");

    char    *str = NULL;
    printf("|rl: duplicate flags: %--i, %00d|\n", 43, 42);
    ft_printf("|ft: duplicate flags: %--i, %00d|\n", 43, 42);
    printf("------------\n");
    printf("|rl: test: %.*i$, %.*i$|\n", -5, 0, -5, 2);
    ft_printf("|ft: test: %.*i$, %.*i$|\n", -5, 0, -5, 2);
    printf("------------\n");
    printf("rl: nullstrings: %s and %8s\n", str, str);
    ft_printf("ft: nullstrings: %s and %8s\n", str, str);
    printf("------------\n");
    return (0);
}
