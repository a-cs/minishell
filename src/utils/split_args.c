/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarneir <acarneir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:53:06 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/09 02:10:10 by acarneir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*save_arg(char *str, int len, int pos)
{
	char	*arg;

	if (pos <= 1)
	{
		str++;
		len--;
	}
	arg = ft_calloc(len + 1, sizeof(char));
	ft_memcpy(arg, str, len);
	return (arg);
}

static int	skip_spaces(t_data *obj, int i, int j)
{
	if ((i + j) < ft_strlen(obj->input) && obj->input[i + j] == SPACE_VALUE)
	{
		j++;
		while ((i + j) < ft_strlen(obj->input) && obj->input[i + j] && obj->input[i + j] == SPACE_VALUE)
			j++;
	}
	return (j);
}

void	split_args(t_data *obj, char **args)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (i < ft_strlen(obj->input) && obj->input[i])
	{
		j = 0;
		if (obj->input[i] == DOUBLE_QUOTES)
			j = increment_count(obj, i, DOUBLE_QUOTES) + 1 - i;
		else if (obj->input[i] == SINGLE_QUOTES)
			j = increment_count(obj, i, SINGLE_QUOTES) + 1 - i;
		if (obj->input[i + j] != DOUBLE_QUOTES
			&& obj->input[i + j] != SINGLE_QUOTES
			&& obj->input[i + j] != SPACE_VALUE)
			j = increment_count(obj, i + j, SPACE_VALUE) - i;
		args[pos] = save_arg(obj->input + i - 1, j + 1, pos);
		pos++;
		j = skip_spaces(obj, i, j);
		i += j;
		// if (i > ft_strlen(obj->input) || obj->input[i] == '\0')
	}
	args[obj->args_num] = NULL ;
}
