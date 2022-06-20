/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 00:53:06 by acarneir          #+#    #+#             */
/*   Updated: 2022/06/20 16:02:47 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static char	*save_arg(char *str, int len)
{
	char	*arg;

	arg = ft_calloc(len + 1, sizeof(char));
	ft_memcpy(arg, str, len);
	return (arg);
}

int	skip_spaces(int i, int j)
{
	if ((i + j) < ft_strlen(g_obj.input) && g_obj.input[i + j] == SPACE_VALUE)
	{
		j++;
		while ((i + j) < ft_strlen(g_obj.input) && g_obj.input[i + j]
			&& g_obj.input[i + j] == SPACE_VALUE)
			j++;
	}
	return (j);
}

int	has_quotes_before_space(char *str)
{
	int	aux_double;
	int	aux_single;
	int	aux_space;

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

void	split_args(char **args)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (i < ft_strlen(g_obj.input) && g_obj.input[i])
	{
		j = increment_quotes(i);
		if ((i + j) < ft_strlen(g_obj.input) && g_obj.input[i + j]
			!= DOUBLE_QUOTES && g_obj.input[i + j] != SINGLE_QUOTES
			&& g_obj.input[i + j] != SPACE_VALUE)
			j = increment_count(i + j, SPACE_VALUE) - i;
		if (pos <= 1)
			args[pos] = save_arg(g_obj.input + i, j);
		else
			args[pos] = save_arg(g_obj.input + i - 1, j + 1);
		pos++;
		j = skip_spaces(i, j);
		i += j;
	}
	args[g_obj.args_num] = NULL;
}
