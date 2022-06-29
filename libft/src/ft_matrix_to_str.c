/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:11:09 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/28 21:18:38 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	conc_str(char **result, char *str)
{
	char	*temp;
	char	*aux;

	temp = ft_strjoin(" ", str);
	aux = ft_strjoin(*result, temp);
	free(*result);
	*result = ft_strdup(aux);
	free(temp);
	free(aux);
}

char	*ft_matrix_to_str(char **matrix)
{
	int		i;
	char	*temp;
	char	*result;

	if (!matrix)
		return (ft_strdup(""));
	i = 0;
	while (matrix[i])
	{
		if (i == 0)
			result = ft_strdup(matrix[i]);
		else
			conc_str(&result, matrix[i]);
		i++;
	}
	temp = ft_strjoin(result, "");
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}
