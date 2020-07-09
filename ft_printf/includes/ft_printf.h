/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 17:50:57 by evelina       #+#    #+#                 */
/*   Updated: 2020/07/09 14:21:45 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

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

int			is_type(int c);
int			is_flag(int c);
long long	ft_atol(const char *str, int *size);
int			get_flags(const char *str, va_list args, t_flags *flags, int *count);
void		check_struct(t_flags *flags, int *count);
int			flags_parser(t_flags *flags, const char *str, va_list args);

int			putchar(int c);
int			putstr(const char *str, t_flags flags);
int			cal_formatlen(const char *str, t_flags flags);
void		print_formatstr(char *str, t_flags flags, int *count);
void		print_format(t_flags flags, va_list args, int *count);

char		*strloc(int len);
char		*convert_c(t_flags flags, va_list args);
char		*convert_s(const char *str, t_flags flags);

int			get_base(char type);
int			number_size(long long nb, int base, t_flags flags);
void		padding_zero(char *str, int len);
char		get_addchar(char type, int num);
char		*assign_int(t_flags flags, long long nb, int len, char *str);
char		*convert_int(t_flags flags, int nb);
char		*convert_unsigned(t_flags flags, unsigned int nb);

int			ul_size(unsigned long nb, int base, t_flags flags);
char		*assign_ulong(t_flags flags, unsigned long nb, int len, char *str);
char		*convert_ulong(t_flags flags, unsigned long nb);

#endif
