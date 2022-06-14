/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/10 01:35:53 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	increment_count(t_data *obj, int i, int c)
{
	i++;
	while (i < ft_strlen(obj->input) && obj->input[i] && obj->input[i] != c)
		i++;
	return (i);
}

int	increment_quotes(t_data *obj, int i)
{
	int	aux_single;
	int	aux_double;
	int	j;

	j = 0;
	while ((i + j) < ft_strlen(obj->input)
		&& has_quotes_before_space(obj->input + i + j))
	{
		if (obj->input[i + j] == DOUBLE_QUOTES)
			j += increment_count(obj, i + j, DOUBLE_QUOTES) + 1 - i - j;
		else if (obj->input[i + j] == SINGLE_QUOTES)
			j += increment_count(obj, i + j, SINGLE_QUOTES) + 1 - i - j;
		else
		{
			aux_double = increment_count(obj, i + j, DOUBLE_QUOTES);
			aux_single = increment_count(obj, i + j, SINGLE_QUOTES);
			if (aux_single < aux_double)
				j += aux_single - i - j;
			else
				j += aux_double - i - j;
		}
	}
	return (j);
}

static void	count_args(t_data *obj)
{
	int	i;
	int	j;

	i = 0;
	while (i < ft_strlen(obj->input) && obj->input[i])
	{
		j = increment_quotes(obj, i);
		if ((i + j) < ft_strlen(obj->input)
			&& obj->input[i + j] != DOUBLE_QUOTES
			&& obj->input[i + j] != SINGLE_QUOTES
			&& obj->input[i + j] != SPACE_VALUE)
			j = increment_count(obj, i + j, SPACE_VALUE) - i;
		obj->args_num++;
		j = skip_spaces(obj, i, j);
		i += j;
	}
}

char	**tokenizer(t_data *obj)
{
	char	**args;

	count_args(obj);
	args = ft_calloc(obj->args_num + 1, sizeof(char *));
	split_args(obj, args);
	return (args);
}
