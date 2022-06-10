/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:53:06 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/10 00:52:23 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	char *save_arg(char *str, int len)
{
	char *arg;

	arg = ft_calloc(len + 1, sizeof(char));
	ft_memcpy(arg, str, len);
	return (arg);
}

int	skip_spaces(t_data *obj, int i, int j)
{
	if ((i + j) < ft_strlen(obj->input) && obj->input[i + j] == SPACE_VALUE)
	{
		j++;
		while ((i + j) < ft_strlen(obj->input) && obj->input[i + j]
			&& obj->input[i + j] == SPACE_VALUE)
			j++;
	}
	return (j);
}

int	has_quotes_before_space(char *str)
{
	int aux_double;
	int aux_single;
	int aux_space;

	if (str[0] == DOUBLE_QUOTES || str[0] == SINGLE_QUOTES)
		return (1);
	else
	{
		aux_space = ft_chrpos(str, SPACE_VALUE);
		aux_double = ft_chrpos(str, DOUBLE_QUOTES);
		aux_single = ft_chrpos(str, SINGLE_QUOTES);
		if (aux_double == -1 && aux_single == -1)
			return (0);
		if (aux_double != -1 && aux_space < aux_double)
			if (aux_single == -1 || aux_space < aux_single)
				return (0);
		if (aux_single != -1 && aux_space < aux_single)
			if (aux_double == -1 || aux_space < aux_double)
				return (0);
	}
	return (1);
}

void	split_args(t_data *obj, char **args)
{
	int i;
	int j;
	int pos;
	int aux_single;
	int aux_double;

	i = 0;
	pos = 0;
	while (i < ft_strlen(obj->input) && obj->input[i])
	{
		j = 0;
		while ((i + j) < ft_strlen(obj->input) && has_quotes_before_space(obj->input + i + j))
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
		if ((i + j) < ft_strlen(obj->input) && obj->input[i + j]
			!= DOUBLE_QUOTES && obj->input[i + j] != SINGLE_QUOTES
			&& obj->input[i + j] != SPACE_VALUE)
			j = increment_count(obj, i + j, SPACE_VALUE) - i;
		if (pos <= 1)
			args[pos] = save_arg(obj->input + i, j);
		else
			args[pos] = save_arg(obj->input + i - 1, j + 1);
		pos++;
		j = skip_spaces(obj, i, j);
		i += j;
	}
	args[obj->args_num] = NULL;
}
