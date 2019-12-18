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

typedef	struct s_pf	t_pf;

struct	s_pf
{
	int	minus;
	int	zero;
	int	apostrophe;
	int	hashtag;
	int	space;
	int	plus;

	int	width;
	int	dot;
	int	precision;

	int	h;
	int	hh;
	int	l;
	int	ll;

	int	len;
};

//int		ft_printf(const char *format, ...);
int		arg_parser(const char *format, ...);
void	ft_reset_spf(struct s_pf t_pf);
#endif
