/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:11:44 by rnovotny          #+#    #+#             */
/*   Updated: 2023/11/01 17:00:00 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int	fd;
	
	if (argc != 1)
	{
		write(2, "Error\n", 6);
		write(2, "Please pass a valid .ber map as a parameter.", 44);
	}
	fd = open(argv[1], O_RDONLY);
	return (0);
}