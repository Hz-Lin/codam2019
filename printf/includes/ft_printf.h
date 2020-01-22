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
	int	printed;
	int	type;
	int	width;
	int	minus;
	int	zero;
	int	dot;
	int	star;
	int	precision;
};

t_struct	ft_struct_init(void);
void		ft_struct_print(t_struct *f);

int			ft_putchar(int c);

int			is_type(int c);
int			is_flag(int c);
int			ft_print_format(int c, t_struct flags, va_list args);

int			format_parser(const char *format, va_list args);
int			flag_parser(const char *format, int i, t_struct *flags, va_list args);

#endif
