/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 15:47:55 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 15:47:58 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*res;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(s1 + i);
	if (len != 0)
	{
		while (s1[len + i - 1] && ft_strchr(set, s1[len + i - 1]) != NULL)
			len--;
	}
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	res = ft_strncpy(res, (s1 + i), len);
	res[len] = '\0';
	return (res);
}

// int		main(void)
// {
// 	char const	s1[] = "  \t \t \n   \n\n\n\t";
// 	char const	s2[] = "";
// 	char const	set[] = " \n\t";

// 	printf("%s\n", ft_strtrim(s1, set));
// 	printf("%s\n", ft_strtrim(s2, set));
// 	return (0);
// }

/* war test */
// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int		main(void)
// {
// 	char	*strtrim;
// 	char 	s1[] = "          ";

// 	printf("%s\n", ft_strtrim(s1, " "));
// 	if (!(strtrim = ft_strtrim(s1, " ")))
// 		ft_print_result("NULL");
// 	else
// 		ft_print_result(strtrim);
// 	if (strtrim == s1)
// 		ft_print_result("\nA new string was not returned");
// 	return (0);
// }
