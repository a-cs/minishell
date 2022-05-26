/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 22:57:30 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/23 23:05:36 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_chrpos(char *s, int c)
{
	int				i;
	unsigned char	*temp;
	unsigned char	temp_c;

	i = 0;
	temp = (unsigned char *)s;
	temp_c = (unsigned char)c;
	while (temp[i] != '\0')
	{
		if (temp[i] == temp_c)
			return (i);
		i++;
	}
	if (temp_c == '\0')
		return (-1);
	return (-1);
}
