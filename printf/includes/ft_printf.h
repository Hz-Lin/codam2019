/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 15:28:58 by hlin          #+#    #+#                 */
/*   Updated: 2019/12/11 17:37:49 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef	struct s_struct	t_struct;

struct	s_struct
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;

	int	len;
};

//int		ft_printf(const char *format, ...);
t_struct	*ft_struct_init(t_struct *f);
void		ft_struct_reset(t_struct *f);
void		ft_struct_print(t_struct *f); //to print the struct


#endif
