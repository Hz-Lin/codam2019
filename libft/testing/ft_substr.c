/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 13:26:36 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/07 13:26:39 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*res;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	res = (char*)malloc(sizeof(*res) * (len + 1));
	if (res == NULL)
		return (NULL);
	while (s[i] != '\0' && i < len && s_len > start)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

// int		main(void)
// {
// 	char const	*str;
// 	char		*res;
// 	char const *s;
	
// 	str = "Precious! My precious! Where is my precious?";
// 	res = ft_substr(str, 10, 12);
// 	printf("%s\n", res);
// 	s = "split  ||this|for|me|||||!|";
// 	printf("%s\n", ft_substr(s, 0, 6));
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

// int		main()
// {
// 	char	str[] = "lorem ipsum dolor sit amet";
// 	char	*strsub;
// 	char	*bullshit;

// 	/* test3 */
// 	// if (!(strsub = ft_substr(str, 7, 0)))
// 	// 	ft_print_result("NULL");
// 	// else
// 	// 	ft_print_result(strsub);
// 	// if (str == strsub)
// 	// 	ft_print_result("\nA new string was not returned");
	
// 	/* test5 */
// 	if (!(strsub = ft_substr(str, 400, 20)))
// 		ft_print_result("NULL");
// 	else
// 	{
// 		bullshit = (char *)&strsub[30];
// 		bullshit = "FULL BULLSHIT";
// 		if (strsub)
// 			ft_print_result(strsub);
// 		else
// 			ft_print_result("rip");
// 	}
// 	if (str == strsub)
// 		ft_print_result("\nA new string was not returned");
// 	return (0);
// }
