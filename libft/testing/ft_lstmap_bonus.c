/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:47:49 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/18 15:47:51 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*tmp;

	if (lst == NULL || f == NULL)
		return (NULL);
	res = NULL;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (tmp == NULL)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}

/* testing the linked list */
void *		lstmap_f(void *content)
{
	(void)content;
	return ("OK !");
}

int		main(void)
{
	t_list	*l = ft_lstnew(strdup(" 1 2 3 "));

	l->next = ft_lstnew(strdup("ss"));
	l->next->next = ft_lstnew(strdup("-_-"));
	
	/* test ft_lstnew */
	// while (l)
	// {
	// 	printf("%s\n", l->content);
	// 	l = l->next;
	// }

	/* test ft_lstsize */
	// printf("%d\n", ft_lstsize(l));

	/* test ft_lstlast */
	// printf("%s\n", (ft_lstlast(l))->content);

	/* test ft_lstadd_front */
	// t_list	*new = ft_lstnew(strdup(" wat "));
	// ft_lstadd_front(&l, new);
	// while (l)
	// {
	// 	printf("%s\n", l->content);
	// 	l = l->next;
	// }

	/* test ft_lstadd_back */
	// t_list	*new = ft_lstnew(strdup(" wat "));
	// ft_lstadd_back(&l, new);
	// while (l)
	// {
	// 	printf("%s\n", l->content);
	// 	l = l->next;
	// }



	/* test ft_lstmap */
	// t_list	*ret;
	// ret = ft_lstmap(l, lstmap_f, NULL);
	// if (!strcmp(ret->content, "OK !") )
	// 	printf("%s\n", ret->content);
	// if (!strcmp(ret->next->content, "OK !"))
	// 	printf("%s\n", ret->next->content);
	// if (!strcmp(ret->next->next->content, "OK !"))
	// 	printf("%s\n", ret->next->next->content);

	return (0);
}
