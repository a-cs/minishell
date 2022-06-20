/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/20 16:06:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	increment_count(int i, int c)
{
	i++;
	while (i < ft_strlen(g_obj.input) && g_obj.input[i] && g_obj.input[i] != c)
		i++;
	return (i);
}

int	increment_quotes(int i)
{
	int	aux_single;
	int	aux_double;
	int	j;

	j = 0;
	while ((i + j) < ft_strlen(g_obj.input)
		&& has_quotes_before_space(g_obj.input + i + j))
	{
		if (g_obj.input[i + j] == DOUBLE_QUOTES)
			j += increment_count(i + j, DOUBLE_QUOTES) + 1 - i - j;
		else if (g_obj.input[i + j] == SINGLE_QUOTES)
			j += increment_count(i + j, SINGLE_QUOTES) + 1 - i - j;
		else
		{
			aux_double = increment_count(i + j, DOUBLE_QUOTES);
			aux_single = increment_count(i + j, SINGLE_QUOTES);
			if (aux_single < aux_double)
				j += aux_single - i - j;
			else
				j += aux_double - i - j;
		}
	}
	return (j);
}

static void	count_args(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen(g_obj.input) && g_obj.input[i])
	{
		j = increment_quotes(i);
		if ((i + j) < ft_strlen(g_obj.input)
			&& g_obj.input[i + j] != DOUBLE_QUOTES
			&& g_obj.input[i + j] != SINGLE_QUOTES
			&& g_obj.input[i + j] != SPACE_VALUE)
			j = increment_count(i + j, SPACE_VALUE) - i;
		g_obj.args_num++;
		j = skip_spaces(i, j);
		i += j;
	}
}

char	**tokenizer(void)
{
	char	**args;

	count_args();
	args = ft_calloc(g_obj.args_num + 1, sizeof(char *));
	split_args(args);
	return (args);
}
