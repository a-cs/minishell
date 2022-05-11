/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:53:10 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/05 21:53:30 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*obj;

	obj = (char *)malloc(count * size);
	if (!obj)
		return (NULL);
	ft_bzero(obj, count * size);
	return ((void *)obj);
}
