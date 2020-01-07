/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   format_parser.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 11:49:26 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/13 11:49:28 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../libft/libft.h"

t_struct	*ft_struct_init(t_struct *f)
{
	f = (t_struct*)malloc(sizeof(t_struct));
	if (f == NULL)
		return (NULL);
	ft_struct_reset(f);
	return (f);
}

void		ft_struct_reset(t_struct *f)
{
	f->minus = 0;
	f->zero = 0;
	// f->apostrophe = 0;
	// f->hashtag = 0;
	// f->space = 0;
	// f->plus = 0;
	f->width = 0;
	f->dot = 0;
	f->precision = 0;
	f->len = 0;
}

void		ft_struct_print(t_struct *f)
{
	printf("minus:      %d\n", f->minus);
	printf("zero:       %d\n", f->zero);
	// printf("apostrophe: %d\n", f->apostrophe);
	// printf("hashtag:    %d\n", f->hashtag);
	// printf("space:      %d\n", f->space);
	// printf("plus:       %d\n", f->plus);
	printf("width:      %d\n", f->width);
	printf("dot:        %d\n", f->dot);
	printf("precision:  %d\n", f->precision);
	printf("len:        %d\n", f->len);
}

// int			main(void)
// {
// 	t_struct	*pf;

// 	pf = NULL;
// 	pf = ft_struct_init(pf);
// 	ft_struct_print(pf);
// 	return (0);
// }
