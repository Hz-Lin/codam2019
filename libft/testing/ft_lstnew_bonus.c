/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 10:40:02 by hlin          #+#    #+#                 */
/*   Updated: 2019/11/18 10:40:04 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list*)malloc(sizeof(*new));
	if (new == NULL)
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
	}
	else
	{
		new->content = (void*)content;
		new->next = NULL;
	}
	return (new);
}
