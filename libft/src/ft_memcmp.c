/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 00:46:33 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/09 01:23:39 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	pos;

	pos = 0;
	while (pos < n)
	{
		if (((unsigned char *)s1)[pos] != ((unsigned char *)s2)[pos])
			return (((unsigned char *)s1)[pos] - ((unsigned char *)s2)[pos]);
		pos++;
	}
	return (0);
}
