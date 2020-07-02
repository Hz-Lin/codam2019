/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: evelina <evelina@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/28 17:50:57 by evelina       #+#    #+#                 */
/*   Updated: 2020/06/24 14:03:39 by evelina       ########   odam.nl         */
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

t_flags		*struct_init(t_flags *flags);
void		check_struct(t_flags *flags, int *count);

int			putchar(int c);
int			putstr(const char *str, t_flags flags);
int			is_type(int c);
int			is_flag(int c);
int			match(char c, char *str);
long long	ft_atol(const char *str, int *size);
int			get_flags(const char *str, va_list args, t_flags *flags, int *count);
int			flags_parser(t_flags *flags, const char *str, va_list args);

//int		print_format(int c, t_flags flags, va_list args);
int			ft_printf(const char *str, ...);

void		struct_print(t_flags *flags);

#endif
