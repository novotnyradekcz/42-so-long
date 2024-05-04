/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:13:08 by rnovotny          #+#    #+#             */
/*   Updated: 2023/01/22 21:03:25 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_neg(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	ft_len(int n, size_t num)
{
	int	l;

	l = 0;
	if (n <= 0)
		l++;
	while (num > 0)
	{
		num /= 10;
		l++;
	}
	return (l);
}

static void	ft_convert(int n, size_t num, size_t l, char *result)
{
	size_t	i;
	size_t	j;
	size_t	ten;

	i = 0;
	j = 0;
	if (n < 0)
	{
		result[i] = '-';
		i++;
	}
	ten = 1;
	while (j++ < (l - i - 1))
		ten *= 10;
	while (i < l)
	{
		result[i] = num / ten + 48;
		num %= ten;
		ten /= 10;
		i++;
	}
	result[i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t	num;
	size_t	l;
	char	*result;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	l = 0;
	num = ft_neg(n);
	l = ft_len(n, num);
	result = (char *)malloc((l + 1) * sizeof(char));
	if (result == 0)
		return (0);
	ft_convert(n, num, l, result);
	return (result);
}
