/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:24:24 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/05 12:47:25 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/so_long.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	result = malloc(nmemb * size);
	if (result == 0)
		return (0);
	ft_bzero(result, nmemb * size);
	return (result);
}
