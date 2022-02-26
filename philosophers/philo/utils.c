/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/12/08 12:22:21 by hlin          #+#    #+#                 */
/*   Updated: 2022/02/23 15:30:31 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != '\0')
		len++;
	if (s != NULL)
		return ((int)write(fd, s, len));
	return (0);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*s1;

	s1 = (t_list *)malloc(sizeof(t_list));
	if (!s1)
		return (NULL);
	s1->content = content;
	s1->next = NULL;
	return (s1);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			last = lst;
		lst = lst->next;
	}
	return (last);
}

void	ft_lstadd_back(t_list **lst, t_list *newnode)
{
	t_list	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}
