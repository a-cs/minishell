/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrqty.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 18:18:33 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/16 22:27:41 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_chrqty(const char *s, int c)
{
	int				i;
	int				qtd;
	unsigned char	*temp;
	unsigned char	temp_c;

	i = 0;
	qtd = 0;
	temp = (unsigned char *)s;
	temp_c = (unsigned char)c;
	while (temp[i] != '\0')
	{
		if (temp[i] == temp_c)
			qtd++;
		i++;
	}
	return (qtd);
}
