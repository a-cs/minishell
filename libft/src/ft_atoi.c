/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 04:14:50 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/09 01:23:39 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_find_start(char const *s1, char *set)
{
	int	i;
	int	start;

	start = 0;
	i = 0;
	while (set[i] != '\0')
	{
		if (s1[start] == set[i])
		{
			start++;
			i = 0;
		}
		else
			i++;
	}
	return (start);
}

int	ft_atoi(const char *str)
{
	int	signal;
	int	number;

	str += ft_find_start(str, " 	\t\n\r\v\f");
	signal = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	number = 0;
	while ((ft_isdigit(*str)))
	{
		number *= 10;
		number += signal * (*str - '0');
		str++;
	}
	return (number);
}
