/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 05:29:20 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/15 01:34:39 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(char *s)
{
	char	*dup;

	dup = (char *)malloc(ft_strlen(s) + 1);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, ft_strlen(s) + 1);
	return (dup);
}
