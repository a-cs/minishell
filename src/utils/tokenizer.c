/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfelipe- <rfelipe-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 00:10:45 by acarneir          #+#    #+#             */
/*   Updated: 2022/05/26 01:39:28 by rfelipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	throw_unclosed_quotes_error(t_data *obj, int pos, int c)
{
	if (obj->input[pos] != c)
	{
		obj->error = 1;
		printf("Error: unclosed quotes\n");
		return (1);
	}
	return (0);
}

static void	check_unclosed_quotes(t_data *obj)
{
	int	pos;

	pos = 0;
	while (pos < ft_strlen(obj->input))
	{
		if (obj->input[pos] == SINGLE_QUOTES)
		{
			pos++;
			while (obj->input[pos] && obj->input[pos] != SINGLE_QUOTES)
				pos++;
			if (throw_unclosed_quotes_error(obj, pos, SINGLE_QUOTES))
				break ;
		}
		else if (obj->input[pos] == DOUBLE_QUOTES)
		{
			pos++;
			while (obj->input[pos] && obj->input[pos] != DOUBLE_QUOTES)
				pos++;
			if (throw_unclosed_quotes_error(obj, pos, DOUBLE_QUOTES))
				break ;
		}
		pos++;
	}
}

char	**tokenizer(t_data *obj)
{
	char	**args;

	check_unclosed_quotes(obj);
	if (obj->error == 0)
	{
		count_tokens(obj);
		args = malloc((obj->args_num + 1) * sizeof(char *));
		split_token(obj, args);
		return (args);
	}
	else
		return (NULL);
}
