/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:11:44 by rnovotny          #+#    #+#             */
/*   Updated: 2023/11/11 21:51:08 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*concatenate(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	s1[i] = *s2;
	i++;
	s1[i] = '\0';
	return (s1);
}

int	read_map(int fd, char **map)
{
	int		i;
	int		readout;
	char	*buffer;
	char	*first_line;

	readout = 1;
	while (readout == 1 && buffer != '\n')
	{
		read(fd, buffer, 1) == 1;
		first_line = concatenate(first_line, buffer);
	}
	return (0);
}

int	check_map()
{
	return (0);
}

int	check_arguments(int argc, char **argv)
{
	int	fd;
	
	if (argc != 1)
	{
		write(2, "Error\n", 6);
		write(2, "Please pass a valid .ber map as an argument.\n", 45);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		write(2, "Unable to read file.\n", 21);
		return (-2);
	}
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;

	fd = check_arguments(argc, argv);
	if (fd < 0)
		return (-fd);
	if (read_map(fd, map))
	{
		write(2, "Error\n", 6);
		write(2, "Passed map is invalid.\n", 23);
		return (3);
	}
	free(map);
	return (0);
}
