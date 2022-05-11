/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 00:32:24 by rfelipe-          #+#    #+#             */
/*   Updated: 2021/11/13 23:15:11 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	size;

	size = 0;
	while (s[size] != '\0')
		size++;
	return (size);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	string = malloc(ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j] != '\0')
	{
		string[i + j] = s2[j];
		j++;
	}
	string[i + j] = '\0';
	return (string);
}

char	*ft_strchr_gnl(char *s)
{
	int		i;
	char	*temp;

	i = 0;
	temp = s;
	while (temp[i] != '\0')
	{
		if (temp[i] == '\n')
			return (temp + i);
		i++;
	}
	return (NULL);
}

char	*ft_strdup_gnl(char *s)
{
	char	*dup;
	int		pos;

	dup = malloc(ft_strlen_gnl(s) + 1);
	pos = 0;
	while (s[pos])
	{
		dup[pos] = s[pos];
		pos++;
	}
	dup[pos] = '\0';
	return (dup);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	substring = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
