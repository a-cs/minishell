/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_to_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 16:11:09 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/25 16:16:21 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
		{
			temp = ft_strjoin(result, ft_strjoin(" ", matrix[i]));
			free(result);
			result = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	temp = ft_strjoin(result, "");
	free(result);
	result = ft_strdup(temp);
	free(temp);
	return (result);
}
