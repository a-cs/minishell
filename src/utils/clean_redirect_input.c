/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirect_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:25:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 20:59:10 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	clean_redirect_input(char **args, char **input)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (ft_chrqty(args[i], '>') == 0 && ft_chrqty(args[i], '<') == 0)
		{
			temp = ft_calloc(ft_strlen(*input) + ft_strlen(args[i]) + 1,
					sizeof(char));
			if (j == 0)
				temp = ft_strdup(args[i]);
			else
				temp = ft_strjoin(*input, ft_strjoin(" ", args[i]));
			free(*input);
			*input = ft_strdup(temp);
			free(temp);
			j++;
		}
		else
			i++;
		i++;
	}
}
