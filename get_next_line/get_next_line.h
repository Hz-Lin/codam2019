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

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		ft_strlen(const char *s);
void	*ft_memmove(void *dst, const void *src, int len);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_is_eol(char *str);
char	*ft_setline(char *s);
int		get_next_line(int fd, char **line);

#endif
