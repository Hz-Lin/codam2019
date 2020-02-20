/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: hlin <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/07 11:55:15 by hlin          #+#    #+#                 */
/*   Updated: 2020/02/07 11:55:17 by hlin          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int		ft_strlen(const char *s);
int		parse(int result, char **line, char **s);
int		free_buffer(char *buffer, int read_bytes, int full);
char	*join_strbuff(char *s, char *buffer, int read_bytes);
void	move_buffer(char *buffer, int read_bytes);

char	ft_realloc(char *s, char *buffer, int read_bytes);
int		is_newline(char *buffer, char **line, int read_bytes);
int		get_next_line(int fd, char **line);

#endif
