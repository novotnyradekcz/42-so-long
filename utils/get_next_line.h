/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:29:14 by rnovotny          #+#    #+#             */
/*   Updated: 2023/02/09 16:01:07 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
char	*output_line(char *mystr);
char	*move_on(char *str);
char	*read_to_string(int fd, char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str, char end);

#endif