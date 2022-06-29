/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_all_blank.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:26:24 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/29 00:38:19 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_is_all_blank(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] == '\t' || str[i] == '\v' || str[i] == '\r'
				|| str[i] == ' '))
			return (0);
		i++;
	}
	return (1);
}
