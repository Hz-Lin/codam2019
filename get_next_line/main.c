/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/12 10:53:50 by hlin          #+#    #+#                 */
/*   Updated: 2020/02/12 10:53:52 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		i;
	int		fd;
	int		gnl_re;
	char	*line;

	if (argc != 2)
	{
		printf("forgot the filename");
		return (-1);
	}
	else
	{
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		fd = open(argv[1], O_RDONLY);
		i = 0;
		if (fd < 0)
		{
			printf("open failed");
			return (-1);
		}
		while ((gnl_re = get_next_line(fd, &line)) == 1)
		{
			printf("%s\n", line);
			printf("gnl_re: %d\n\n", gnl_re);
			free(line);
		}
		if (gnl_re == -1)
			printf("error\n");
		else if (gnl_re == 0)
		{
			printf("gnl_re: %d\n EOF\n", gnl_re);
			free(line);
		}
		close(fd);
	}
	return (0);
}
