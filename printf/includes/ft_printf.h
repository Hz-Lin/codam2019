/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 17:50:57 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/06 00:34:59 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flags	t_flags;

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

t_flags		*struct_init(t_flags *flags);
void		check_struct(t_flags *flags, int *count);
void		struct_print(t_flags *flags);

int			is_type(int c);
int			is_flag(int c);
long long	ft_atol(const char *str, int *size);
int			get_flags(const char *str, va_list args, t_flags *flags, int *count);
int			flags_parser(t_flags *flags, const char *str, va_list args);

int			putchar(int c);
int			putstr(const char *str, t_flags flags);
int			cal_formatlen(const char *str, t_flags flags);
void		print_output(char *str, t_flags flags, int *count);
void		print_format(t_flags flags, va_list args, int *count);

char		*strloc(int len); //ft_calloc
char		*convert_c(t_flags flags, va_list args);
char		*convert_s(const char *str, t_flags flags);

int			get_base(char type);
int			number_size(long long nb, int base, t_flags flags);
char		get_addchar(char type, int num);
char		*number_to_str(t_flags flags, long long nb, int len, char *str);
char		*convert_int(t_flags flags, int nb);
char		*convert_unsigned(t_flags flags, unsigned long nb);

#endif
