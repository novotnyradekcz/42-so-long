/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnovotny <rnovotny@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:46:56 by rnovotny          #+#    #+#             */
/*   Updated: 2024/05/04 18:08:54 by rnovotny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

void*	ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);
char*	ft_itoa(int n);
char	*ft_strdup(const char *str);

#endif