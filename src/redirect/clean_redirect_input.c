/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_redirect_input.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 20:25:01 by rfelipe-          #+#    #+#             */
/*   Updated: 2022/06/26 02:53:50 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	update_input(char **input, char *arg, int j)
{
	char	*temp;
	char	*aux;

	if (j == 0)
		temp = ft_strdup(arg);
	else
	{
		aux = ft_strjoin(" ", arg);
		temp = ft_strjoin(*input, aux);
		free(aux);
	}
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
		if ((ft_chrqty(args[i], '>') == 0 && ft_chrqty(args[i], '<') == 0)
			|| (args[i][0] != '>' && args[i][0] != '<'))
			j = update_input(input, args[i], j);
		else
			i++;
		i++;
	}
	if (j == 0 && args[j] && (ft_chrqty(args[0], '>') != 0
			|| ft_chrqty(args[0], '<') != 0))
	{
		free(*input);
		*input = ft_strjoin("", "");
	}
}
