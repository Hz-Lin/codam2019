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

typedef	struct s_pf	t_pf;

struct	s_pf
{
	int	index;
	int	len;
	int	fd;

	int	minus;
	int	plus;
	int	space;
	int	zero;
	int	hashtag;

	int	width;
	int	precision_sp;
	int	precision;
	int	length;
};

//int		ft_printf(const char *format, ...);
int		arg_parser(const char *format, ...);
#endif
