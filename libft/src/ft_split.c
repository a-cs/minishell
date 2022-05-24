/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 00:17:29 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/05/23 23:05:36 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	*ft_free_result(char **result)
{
	int	i;

	i = 0;
	while (result[i])
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static size_t	ft_wrd_size(char *s, char c)
{
	size_t	pos;

	pos = 0;
	while (s[pos] && s[pos] != c)
		pos++;
	return (pos);
}

static size_t	ft_nbr_wrd(char *s, char c)
{
	size_t	nbr_wrd;
	size_t	pos;

	nbr_wrd = 0;
	pos = 0;
	if (!s[0])
		return (0);
	while (s[pos] != '\0' && s[pos] == c)
		pos++;
	while (s[pos] != '\0')
	{
		if (s[pos] == c)
		{
			nbr_wrd++;
			while (s[pos] != '\0' && s[pos] == c)
				pos++;
			continue ;
		}
		pos++;
	}
	if (s[pos - 1] != c)
		nbr_wrd++;
	return (nbr_wrd);
}

static char	*ft_put_wrd(char *s, size_t size)
{
	size_t	i;
	char	*temp;

	temp = ft_calloc(size + 1, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < size)
	{
		temp[i] = s[i];
		i++;
	}
	return (temp);
}

char	**ft_split(char *s, char c)
{
	size_t	nbr_wrd;
	size_t	index;
	char	**result;

	if (!s)
		return (NULL);
	nbr_wrd = ft_nbr_wrd(s, c);
	result = (char **)malloc((nbr_wrd + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	index = 0;
	while (index < nbr_wrd)
	{
		if (ft_wrd_size(s, c))
		{
			result[index] = ft_put_wrd(s, ft_wrd_size(s, c));
			if (!result[index++])
				return (ft_free_result(result));
		}
		s += ft_wrd_size(s, c) + 1;
	}
	result[index] = NULL;
	return (result);
}
