/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   display_parser.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <hlin@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/06 23:37:39 by hlin          #+#    #+#                 */
/*   Updated: 2021/09/21 13:06:46 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	init_display(t_display *dsp)
{
	dsp->debug = 0;
	dsp->colors = 0;
	dsp->count = 0;
	dsp->moves = 0;
	dsp->flags = 0;
}

void	parse_display(char **argv, t_display *dsp)
{
	int	i;

	init_display(dsp);
	i = 1;
	while (argv[i])
	{
		if (ft_strequ(argv[i], "-v"))
			dsp->debug = 1;
		else if (ft_strequ(argv[i], "-c"))
			dsp->colors = 1;
		else if (ft_strequ(argv[i], "-m"))
			dsp->count = 1;
		i++;
	}
	dsp->flags = dsp->debug + dsp->colors + dsp->count;
}
