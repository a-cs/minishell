/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 04:45:50 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/17 19:39:27 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	ft_itoa_part_2(char *str, char nb[])
{
	int	size;
	int	i;

	size = ft_strlen(nb) - 1;
	i = 0;
	if (nb[0] == '-')
	{
		str[0] = '-';
		i++;
	}
	while (size >= 0 && nb[size] != '-')
	{
		str[i] = nb[size];
		i++;
		size--;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	int		i;
	char	nb[12];
	char	*str;

	i = 0;
	while (i < 12)
	{
		if (n < 0)
		{
			if (i == 0)
				nb[i++] = '-';
			nb[i] = (n % 10) * (-1) + '0';
		}
		else if (n == 0 && i != 0)
			nb[i] = '\0';
		else
			nb[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str = (char *)malloc(ft_strlen(nb) + 1);
	if (!str)
		return (NULL);
	ft_itoa_part_2(str, nb);
	return (str);
}
