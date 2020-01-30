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

int			is_type(int c);
int			is_flag(int c);
int			ft_print_format(int c, t_struct flags, va_list args);

t_struct	parse_minus(t_struct flags);
t_struct	parse_digit(t_struct flags, char c);
t_struct	parse_width(t_struct flags, va_list args);
int			parse_dot(const char *format, int i, t_struct *flags, va_list args);

int			format_parser(const char *format, va_list args);
int			flag_parser(const char *format, int i, t_struct *flags, va_list args);

int			ft_putchar(int c);
int			ft_putstrprec(char *str, int len);
int			cal_width(int width, int minus, int zero);
char		*ft_str_tolower(char *str);

int			ft_print_char(char c, t_struct flags);
int			ft_print_str(char *str, t_struct flags);
int			ft_put_part_int(char *str, t_struct flags);


int			ft_print_percent(t_struct flags);

int			ft_print_int(int i, t_struct flags);
#endif
