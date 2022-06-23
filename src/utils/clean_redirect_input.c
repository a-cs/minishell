/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirect_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:25:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/22 23:57:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	update_input(char **input, char *arg, int j)
{
	char	*temp;

	temp = ft_calloc(ft_strlen(*input) + ft_strlen(arg) + 1, sizeof(char));
	if (j == 0)
		temp = ft_strdup(arg);
	else
		temp = ft_strjoin(*input, ft_strjoin(" ", arg));
	free(*input);
	*input = ft_strdup(temp);
	free(temp);
	j++;
	return (j);
}

void	clean_redirect_input(char **args, char **input)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (args[i])
	{
		if (ft_chrqty(args[i], '>') == 0 && ft_chrqty(args[i], '<') == 0)
			j = update_input(input, args[i], j);
		else
			i++;
		i++;
	}
	if (j == 0 && (ft_chrqty(args[0], '>') != 0
			|| ft_chrqty(args[0], '<') != 0))
	{
		free(*input);
		*input = ft_strjoin("", "");
	}
}
