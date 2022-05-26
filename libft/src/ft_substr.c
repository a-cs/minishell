/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 02:41:12 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/23 23:07:47 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	if (!s)
		return (NULL);
	if (start > (unsigned int)ft_strlen(s))
		i = 1;
	else if (start + len > (unsigned int)ft_strlen(s))
		i = (unsigned int)ft_strlen(s) - start + 1;
	else
		i = len + 1;
	substring = (char *)ft_calloc(i, sizeof(char));
	if (!substring)
		return (NULL);
	if (i > 1)
	{
		i = 0;
		while (i < len && s[start + i] != '\0')
		{
			substring[i] = s[start + i];
			i++;
		}
	}
	return (substring);
}
