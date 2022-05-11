/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 21:36:56 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/05 21:41:20 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	pos;
	int	size;

	pos = 0;
	size = ft_strlen(str);
	while (pos < size)
	{
		ft_putchar_fd(str[pos], fd);
		pos++;
	}
}
