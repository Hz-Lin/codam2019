/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstsize_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:39:17 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/18 12:39:19 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		lst_len;

	tmp = lst;
	lst_len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		lst_len++;
	}
	return (lst_len);
}
