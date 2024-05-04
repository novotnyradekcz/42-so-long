/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:28:35 by rnovotny          #+#    #+#             */
/*   Updated: 2023/04/30 15:24:42 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*output_line(char *mystr)
{
	int		i;
	char	*outputline;

	i = 0;
	outputline = (char *)malloc((ft_strlen(mystr, '\n') + 2) * sizeof(char));
	if (!outputline)
		return (0);
	while (mystr[i] != '\n' && mystr[i] != '\0')
	{
		outputline[i] = mystr[i];
		i++;
	}
	outputline[i] = mystr[i];
	outputline[i + 1] = '\0';
	return (outputline);
}

char	*get_next_line(int fd)
{
	char		*outputline;
	static char	*mystring;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	mystring = read_to_string(fd, mystring);
	if (!mystring)
		return (0);
	if (!mystring[0])
		outputline = 0;
	else
		outputline = output_line(mystring);
	mystring = move_on(mystring);
	return (outputline);
}
