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
	int		fd;
	int		ret;
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
		ret = 1;
		while (ret > 0)
		{
			ret = get_next_line(fd, &line);
			printf("%s\n", line);
			printf("ret: %d\n", ret);
			free(line);
		}
		if (ret == -1)
			printf("error\n");
		close(fd);
	}
	return (1);
}

// int		main()
// {
// 	int		ret;
// 	char	*line;

// 	printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
// 	ret = 1;
// 	while (ret > 0)
// 	{
// 		ret = get_next_line(0, &line);
// 		printf("%s\n", line);
// 		printf("ret: %d\n", ret);
// 		free(line);
// 	}
// 	if (ret == -1)
// 		printf("error\n");
// 	return (1);
// }
