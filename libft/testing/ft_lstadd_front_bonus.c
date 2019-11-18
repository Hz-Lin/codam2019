/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstadd_front_bonus.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:11:40 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/18 12:11:43 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (alst == NULL || new == NULL)
		return ;
	new->next = *alst;
	*alst = new;
}

// int		main(void)
// {
//     t_list *list = ft_lstnew("list0");
// 	list->next = ft_lstnew("list1");
// 	t_list *new = ft_lstnew("newlist");
// 	ft_lstadd_front(&list, new);
// 	//printf("%s",ft_strccpy(c1,c4,'x'));
// 	while (list->content)
// 	{
// 		printf("%s\n", list->content);
// 		list++;
// 	}
// 	return 0;
// }
