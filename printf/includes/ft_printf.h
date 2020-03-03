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

typedef	struct s_flags	t_flags;

struct	s_flags
{
	char	type;
	int		min_width;
	int		max_width;
	int		precision;
	int		left_align;
	char	padding;
};

int			ft_printf(const char *str, ...);
int			ft_putchar(int c);
long long	ft_atoi_long(char *str, int *size);

int			is_type(int c);
int			is_flag(int c);

t_flags		*ft_struct_init(t_flags *flags);
void		check_struct(t_flags *flags, int *count);
void		ft_struct_print(t_flags *f); //for testing

int			format_parser(const char *str, va_list args, t_flags *flags, int *count);
int			flag_parser(const char *str,  t_flags *flags, va_list args);

// t_args	ft_struct_init(void);
// void		ft_struct_print(t_struct *f);

// int			is_type(int c);
// int			is_flag(int c);
// int			ft_print_format(int c, t_struct flags, va_list args);

// t_struct	parse_minus(t_struct flags);
// t_struct	parse_digit(t_struct flags, char c);
// t_struct	parse_width(t_struct flags, va_list args);
// int			parse_dot(const char *format, int i, t_struct *flags, va_list args);



// int			ft_putchar(int c);
// int			ft_putstr_prec(char *str, int len);
// int			ft_spaceholder(int width, int str_len, int zero);
// char		*ft_str_tolower(char *str);

// int			ft_print_char(char c, t_struct flags);
// int			ft_print_str(char *str, t_struct flags);
// int			ft_put_part_int(char *str, t_struct flags);

// int			ft_print_percent(t_struct flags);

// int			ft_print_int(int i, t_struct flags);
// int			ft_print_uint(unsigned int n, t_struct flags);

#endif
